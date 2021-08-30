#include <iostream> 
#include <fstream>
#include <string>

bool validator(std::string data){
  int day = 0;
  int mount = 0;
  int year = 0;
  day = std::stoi(data.substr(0,2));
  mount = std::stoi(data.substr(3,2));
  year = std::stoi(data.substr(6,4));
  if(day < 0 || day > 31 || mount < 0 || mount > 12 || year < 0){
    return false;
  }
}

int main(){
  std::cout << "Accounting statement" << std::endl;
  std::string name;
  std::string data;
  int amount = 0;
  std::ofstream file("..\\src\\File\\file.txt", std::ios::app);
  std::cout << "Enter your last name and first name." << std::endl;
  std::getline(std::cin, name);
  std::cout << "Enter the date (dd. mm. yyyy)" << std::endl;
  std::cin >> data;
  if(!validator(data)){
    data = "ERROR";
  }
  std::cout << "Enter the amount in RUB" << std::endl;
  std::cin >> amount;

  file << name  << " " << data << " " << amount << "\n";
  file.close();

  return 0;
}

// Что нужно сделать

// В одном из прошлых заданий мы уже создавали программу 
// чтения и анализа ведомости выплат. Теперь требуется 
// создать простую программу записи в эту ведомость.

// Формат ведомости прежний. Сначала идёт имя и 
// фамилия получателя денежных средств, далее 
// располагается дата выдачи в формате ДД.ММ.ГГГГ. 
// Завершает запись сумма выплаты в рублях. 
// Данные разделяются между собой пробелами. 
// В конце каждой записи должен быть расположен перевод строки.

// При старте программы пользователь последовательно 
// вводит данные для новой записи, которые записываются 
// затем в файл в текстовом режиме. Программа должна 
// добавлять новые записи в конец файла, не удаляя его текущее содержимое.



// Советы и рекомендации

// Введённые данные рекомендуется хотя бы 
// минимально валидировать перед их записью. 

// Для валидации даты в указанном формате можно 
// использовать функции std::stoi и std::subtr с 
// корректно указанным диапазоном символов в дате. 
// К примеру, вызов std::stoi(date.substr(3, 2)) 
// вычленит из строковой даты целочисленный месяц для последующего анализа.
