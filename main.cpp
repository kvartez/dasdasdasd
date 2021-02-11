#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

char buff[33];
int countstring(int num,int base,string find_= itoa(6,buff,10)){
	string number = itoa(num,buff,base);
    int count;
    for(int i = 0 ; i<number.length();++i){
        if(number[i]==find_[0]){
            ++count; 
        }
    }
    return count;
}
int countint(int num,int base ,int find=6){
	int count;
	while(num){
		if(num%base==find){
			++count;
		}
		num /=base;
	}
	return count;
}


int main() {
	int find = 6;
    ifstream file;
    file.open("liczby2.txt");
    int number;
    int countdec=0,countoct=0;
    if(file.good()){
        for(int i = 0 ; i<1000;++i){
            file >> number;
            countdec +=countint(number,10);
            countoct +=countint(number,8);
        }
    }
    cout << "times " << find <<" been in dec numbers :" << countdec <<endl;
    cout << "times " << find <<" been in oct numbers :" << countoct <<endl;
    return 0;
}
