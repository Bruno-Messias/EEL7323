#ifndef POOL_CONTROLER_H
#define POOL_CONTROLER_H

class PoolControler
{
public:
	PoolControler();
	~PoolControler();
	virtual void FSM() = 0;
	virtual void Inputs() = 0;
	virtual void Outputs() = 0;
};


#endif // !POOL_CONTROLER_H

