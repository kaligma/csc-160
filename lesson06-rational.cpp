class Rational
{
private:
  int get_num();//function to get numerator
  int get_denom();//function to get denominator
  void reduce(int&, int&);//function to reduce fractions
  int num;//variable to hold numerator
  int dnum;//variable to hold denominator
  
public:
  Rational();//default constructor
  Rational(int new_num, int new_dnum);//constructor
  Rational add(Rational&);//function to add objects
  Rational sub(Rational&);//function to subtract objects
  Rational mul(Rational&);//function to multiply objects
  Rational div(Rational&);//function to divide objects
  bool less(Rational&);//function to determine greater/lesser of objects
  void input(istream& istr);//input function
  void output(ostream& ostr, bool nl = true);//output function
  
};//end class def.
