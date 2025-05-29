# Виртуални таблици
- примерна имплементация на динамичното свързване
- стандартът на C++ не определя как трябва да бъдат реализирани виртуалните функции (тази подробност е оставена на имплементацията).
- обикновено се използва виртуална таблица - таблица за търсене на функции, която се използва за разрешаване на извикванията на функции при динамично свързване
- съдържа по един запис за всяка виртуална функция, която може да бъде извикана от обекти на класа
- всеки запис в тази таблица е указател към функция, който сочи към най-късно имплементираната функция, достъпна от този клас
- добавя се и скрит указател, който е член на базовия клас - `*__vptr`, т.е. се пази допълнителна памет
- 2 дереферирания
- всяка виртуална таблица се отнася за целия клас, не конкретен обект


# Хетерогенен контейнер
- клас, който съдържа колекция от указатели към базов клас в полиморфна йерархия
- колекция от различни типове (но с общ базов клас)
- менажира своето копиране, триене и т.н.

```c++
struct Fruit
{
	virtual void printColor() const = 0;
	
	virtual ~Fruit() = default;
};

struct Apple : public Fruit
{
	 void printColor() const override
	{
		std::cout << "Red or green! "<<std::endl;
	}
};

struct Orange : public Fruit
{
	void printColor() const override
	{
		std::cout << "Orange! "<<std::endl;
	}
	
};

struct Lemon : public Fruit
{
	Lemon(size_t sourness) : sourness(sourness){}
	
	size_t sourness;
	void printColor() const override
	{
		std::cout << "Yellow! "<<std::endl;
	}
};

class FruitStore
{
private:
	Fruit** fruits;
	size_t capacity;
	size_t count;
          
    void copyFrom(const FruitStore& other);
    void free();
    
public:
	FruitStore();
	FruitStore(const FruitStore&);
	FruitStore& operator=(const FruitStore&);
       ~FruitStore();
	
	void addFruit(Fruit* fr);
};

void FruitStore::addFruit(Fruit* fr)
{
	fruits[count++] = fr;
}
int main()
{
	FruitStore store;
	store.addFruit(new Lemmon(3));
	store.addFruit(new Apple());
}
```

## Триене
- виртуален деструктор в базовия клас - не се интересуваме в колекцията какви са обектите, които трием
```c++
void FruitStore::free()
{
	for(int i = 0; i < count; i++)
		delete fruits[i];
	delete[] fruits;
}
 ```

## Копиране
- клониране - функция, която всеки обект прави копие на себе си

```c++

struct Fruit
{
	virtual void printColor() const = 0;
	virtual ~Fruit(){}

      	virtual Fruit* clone() const = 0; //!
};

struct Apple : public Fruit
{
	 void printColor() const override
	{
		std::cout << "Red or green! "<<std::endl;
	}
	Fruit* clone() const override
	{
		return new Apple(*this);
    	}
	
};

struct Orange : public Fruit
{
	void printColor() const override
	{
		std::cout << "Orange! "<<std::endl;
	}
	
	Fruit* clone() const override
	{
		return new Orange(*this);
	}
};

struct Lemon : public Fruit
{
	Lemon(size_t sourness) : sourness(sourness){}
	
	size_t sourness;
	void printColor() const override
	{
		std::cout << "Yellow! "<<std::endl;
	}
	Fruit* clone() const override
	{
		return new Lemon(*this);
    	}
};
 ```

```c++
void FruitStore::copyFrom(const FruitStore& other)
{
	fruits = new Fruit*[other. capacity];
	for(int i = 0; i < other.count; i++)
		fruits[i] = other.fruits[i]->clone();
	count = other.count;
	capacity = other.capacity;
}
 ```