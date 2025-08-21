#include <iostream>
#include <assert.h>

class BooleanInterpretation
{
public:
	void set(char ch, bool value)
	{
		assert(ch >= 'a' && ch <= 'z');
		values[ch - 'a'] = value;
	}
	bool operator()(char ch) const
	{
		assert(ch >= 'a' && ch <= 'z');
		return values[ch - 'a'];
	}
private:
	bool values[26]{ false }; //a->
};


struct BooleanExpression
{
	BooleanExpression() = default;
	BooleanExpression(const BooleanExpression&) = delete;
	BooleanExpression& operator=(const BooleanExpression&) = delete;

	virtual bool eval(const BooleanInterpretation& interpet) const = 0;
	virtual ~BooleanExpression() = default;
	virtual BooleanExpression* clone() const = 0;

	virtual void populateVariables(BooleanInterpretation& interpret) const = 0;
};

struct Var : BooleanExpression
{
	Var(char ch) :ch(ch) {}
	bool eval(const BooleanInterpretation& interpet) const override
	{
		return interpet(ch);
	}

	virtual BooleanExpression* clone() const override
	{
		return new Var(ch);
	}

	void populateVariables(BooleanInterpretation& interpret) const override
	{
		interpret.set(ch, true);
	}

private:
	char ch;
};

struct UnaryOperation : BooleanExpression
{
	UnaryOperation(BooleanExpression* expr) : expr(expr) {}

	void populateVariables(BooleanInterpretation& interpret) const override
	{
		expr->populateVariables(interpret);
	}

	~UnaryOperation()
	{
		delete expr;
	}
protected:
	BooleanExpression* expr;
};
struct Negation : UnaryOperation
{
	Negation(BooleanExpression* expr) : UnaryOperation(expr) {}
	virtual BooleanExpression* clone() const override
	{
		return new Negation(expr->clone());
	}
	bool eval(const BooleanInterpretation& interpet) const override
	{
		return !expr->eval(interpet);
	}
};

struct BinaryOperation : BooleanExpression
{
	BinaryOperation(BooleanExpression* left, BooleanExpression* right) : left(left), right(right) {}

	void populateVariables(BooleanInterpretation& interpret) const override
	{
		left->populateVariables(interpret);
		right->populateVariables(interpret);
	}

	~BinaryOperation()
	{
		delete left;
		delete right;
	}
protected:
	BooleanExpression* left;
	BooleanExpression* right;
};

struct Conjunction : BinaryOperation
{
	Conjunction(BooleanExpression* left, BooleanExpression* right) : BinaryOperation(left, right) {}

	virtual BooleanExpression* clone() const override
	{
		return new Conjunction(left->clone(), right->clone());
	}

	bool eval(const BooleanInterpretation& interpet) const override
	{
		return left->eval(interpet) && right->eval(interpet);
	}

};

struct Disjunction : BinaryOperation
{
	Disjunction(BooleanExpression* left, BooleanExpression* right) : BinaryOperation(left, right) {}

	virtual BooleanExpression* clone() const override
	{
		return new Disjunction(left->clone(), right->clone());
	}
	bool eval(const BooleanInterpretation& interpet) const override
	{
		return left->eval(interpet) || right->eval(interpet);
	}
};

int main() {
	BooleanInterpretation interpret;
	interpret.set('a', true);
	interpret.set('b', false);
	interpret.set('c', true);

	BooleanExpression* expr = new Disjunction(new Conjunction(new Var('a'), new Var('b')), new Negation(new Var('c')));
	std::cout << expr->eval(interpret);
}
