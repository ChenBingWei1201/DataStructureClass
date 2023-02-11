#pragma once
template<class T1, class T2>
class CFraction
{
public:
	CFraction();
	CFraction(T1 num, T2 den);
	~CFraction();
	void SetMunerator(T1 num);
	void SetDenominator(T2 den);
	void print();
private:
	T1 m_Numerator;
	T2 m_Denomiator;
};

template<class T1, class T2>
inline CFraction<T1, T2>::CFraction() : m_Numerator(), m_Denomiator()
{

}

template<class T1, class T2>
inline CFraction<T1, T2>::CFraction(T1 num, T2 den)
{
	m_Numerator = num;
	m_Denomiator = den;
}

template<class T1, class T2>
inline CFraction<T1, T2>::CFraction::~CFraction()
{

}

template<class T1, class T2>
void SetMunerator(T1 num)
{
	m_Numerator = num;
}