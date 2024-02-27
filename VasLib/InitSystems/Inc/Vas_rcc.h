#ifndef Vas_Cpp_H
#define Vas_Cpp_H

struct pll_config
{
	bool State = false;
	bool SourceHSE = false;
	unsigned int Mul = 4;
};

struct HSE_config
{
	bool State = false;
	unsigned int Frequency = 8;
	unsigned int PreDiv = 1;
};

struct HSI_config
{
	bool State = true;
	unsigned int Frequency = 8;
};

struct rcc_mode_config
{
	HSI_config HSI;
	HSE_config HSE;
	pll_config PLL;
	unsigned int AHB_Div = 1;
	unsigned int APB1_scale = 1;
};



class rcc_system
{
private:
	rcc_mode_config rcc;
	bool init_HSE(void);
	bool init_HSI(void);
public:
	rcc_system();
	rcc_system(short mode);

	bool init(void);
	unsigned int print_freeq();
};

#endif
