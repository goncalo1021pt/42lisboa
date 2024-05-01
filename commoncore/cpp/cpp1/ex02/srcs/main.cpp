# include <iostream>
# include <string>
typedef std::string t_string;
using std::cout;
using std::endl;

int main() {
	t_string name = "HI THIS IS BRAIN";
	t_string *ptr = &name;
	t_string &ref = name;

	cout << &name << endl;
	cout << ptr << endl;
	cout << &ref << endl;
	cout << name << endl;
	cout << *ptr << endl;
	cout << ref << endl;
}
