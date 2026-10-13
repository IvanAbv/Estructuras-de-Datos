
template <typename T>
class sumatemplate{
private:
    T num1;
    T num2;

public:
    // Constructor
    sumatemplate(T n1, T n2);
    
    // Setters
    void setNum1(T n1);
    void setNum2(T n2);

    // Getters
    T getNum1();
    T getNum2();
    
    // Metodo de suma
    void sumar();


    // Destructor
    ~sumatemplate(){};

};

