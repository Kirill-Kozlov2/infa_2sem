#include <iostream>

struct string {
    char *str;
    size_t size;
    size_t cap;

    string() // Конструктор пустой строки
    {
        str = NULL;
    }

    string(size_t cnt, char c) // Заполняющий конструктор
    {
        size = cnt;
        cap = 1;
        while (cap < size)
            cap = cap * 2;
        str = new char[cap + 1];
        for (int j = 0; j < size; j++)
            str[j] = c;
        str[cnt] = '/0';
    }

    string(const string& s) // Копирующий конструктор
    {
        size = s.size;
        cap = s.cap;
        str = new char[cap + 1];
        for (int j = 0; j <= size; j++)
            str[j] = s[j];
    }

    string(char c)  // Конструктор строки из одного символа
    {
        cap = 1;
        size = 1;
        str = new char[cap + 1];
        str[0] = c;
        str[1] = '\0';
    }

    string(const char *c_str)  // Конструктор строки из c-style строки (массива символов)
    {
        size = 0;
        while (c_str[size] != '\0')
            size++;
        cap = 1;
        while (cap < size)
            cap = cap * 2;
        str = new char[cap + 1];
        for (int j = 1; j <= size; j++)
            str[j] = c_str[j];
    }

    ~string() // Очистить всю используемую память
    {
        delete [] str;
        str = NULL;
        size = 0;
        cap = 0;
    }

    string& operator= (const string& new_str)
    {
        size = new_str.size;
        size_t new_cap = 1;
        while (new_cap < size)
            new_cap = new_cap * 2;
        reserve(new_cap);
        for (int j = 0; j <= size; j++)
             str[j] = new_str[j];
        return *this;
    }

    bool operator== (const string& other)
    {
        bool flag = false;
        if (size == other.size)
        {
            int j = 0;
            while (other[j] == str[j] && other[j] != '\0')
                j++;
            if (j = size)
                flag = true;
        }
        return flag;
    }

    bool operator!= (const string& other)
    {
        bool flag = false;
        if (*this == other)
            flag = true;
        return flag;
    }

    bool operator> (const string& other)
    {
        bool flag = false;
        if (size > other.size)
            flag = true;
        else if (size = other.size)
        {
            int j = 0;
            while (other[j] == str[j] && other[j] != '\0')
                j++;
            if (str[j] > other[j])
                flag = true;
        }
        return flag;
    }

    bool operator< (const string& other)
    {
        bool flag = true;
        if ((*this > other) || (*this == other))
            flag = false;
        return flag;
    }

    string& operator+= (const string& other)
    {
        size_t new_size = size + other.size;
        size_t new_cap = 1;
        while (new_cap < new_size)
            new_cap = new_cap * 2;
        reserve(new_cap);
        for (int j = size; j < new_size; j++)
            str[j] = other[j - size];
        str[new_size] = '\0';
        size = new_size;
        return *this;
    }

    char operator[] (unsigned int pos) const
    {
        return str[pos];
    }

    void append(const string other) // Дописать в конец данной строки другую
    {
        *this += other;
    }

    void resize(unsigned int new_cap) // Увеличить/уменьшить емкость строки
    {
        if (size >= new_cap)
        {
            cap = new_cap;
            size = new_cap;
            str[size] = '\0';
        }
        else
            reserve(new_cap);
    }

    void reserve(unsigned int new_cap) // Зарезервировать память в нужном объеме
    {
        if (cap < new_cap)
        {
            cap = new_cap;
            char * new_str = new char[cap + 1];
            for (int j = 0; j <= size; j++)
                new_str[j] = str[j];
            delete [] str;
            str = new_str;
        }
    }

    void insert(unsigned int pos, string other) {}  // Вставка другой строки внутрь данной

    void shrink_to_fit() // Очистить неиспользуемую память
    {
        (*this).resize(size);
    }

    void clear() // Очистить содержимое строки, занимаемое место при этом не меняется
    {
        for (int j = 1; j <= size; j++)
            str[j] = '0';
        str[0] = '\0';
        size = 0;
    }

    friend std::ostream& operator<< (std::ostream& ostr, const string& str)
    {
        for (int j = 0; j < str.size; j++)
            ostr << str[j];
        return ostr;
    }

    friend std::istream& operator>> (std::istream& istr, const string& str)
    {
        istr >> str.str;
        return istr;
    }

};


string operator + (const string & str1, const string & str2)
{
    string new_str(str1);
    new_str += str2;
    return new_str;
}

int stoi(const string str, size_t pos = 0, int base = 10 );
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.

int main()
{
    string empty_str();

    char element;
    std::cout << "Enter element which you want to display: ";
    std::cin >> element;
    string one_element(element);
    std::cout << one_element << '\n';

    std::cout << "Enter number of elements and element: ";
    size_t number;
    std::cin >> number >> element;
    string fill_str(number, element);
    std::cout << "Fill string: ";
    std::cout << fill_str << '\n';

    std::cout << "Copy string: ";
    string copy_str(fill_str);
    std::cout << copy_str << '\n';

    std::cout << "Double string: ";
    fill_str += fill_str;
    std::cout << fill_str << '\n';

    return 0;
}
