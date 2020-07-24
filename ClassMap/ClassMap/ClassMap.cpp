#include <iostream>
#include <vector>

struct StudentGrade {
    std::string m_name;
    char m_mark;
};

class GradeMap {
private:
    std::vector<StudentGrade> m_map;
public:
    GradeMap()
    {

    }

    char& operator[](const std::string &name);
};

char& GradeMap::operator[](const std::string &name) {
    for (auto& student : m_map) {
        if (student.m_name == name)
        return student.m_mark;
    } 
    StudentGrade stud{name, ' '};
    m_map.push_back(stud); // дин. массив удаляет свой старый блок память, 
                           //копирует данные в новый блок памяти
    return m_map.back().m_mark;
}

int main()
{
    GradeMap grades;
    grades["John"] = 'A';
    grades["Martin"] = 'B';
    std::cout << "John has a grade of " << grades["John"] << '\n';
    std::cout << "Martin has a grade of " << grades["Martin"] << '\n';

    GradeMap grades;
    //1)
    char& gradeJohn = grades["John"];
    gradeJohn = 'A';// ссылка на отметку активна
    //2)
    char& gradeMartin = grades["Martin"]; //при добавлении, дин. массив удаляет свой старый блок память, 
                                          //копирует данные в новый блок памяти, поэтому все ссылки которые мы сохранили(gradeJohn)
                                          //будет указывать на мусор
    gradeMartin = 'B';

    std::cout << "John has a grade of " << gradeJohn << '\n'; //выведится мусор
    std::cout << "Martin has a grade of " << gradeMartin << '\n';

}

