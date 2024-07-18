#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::vector<int> scores;
    int totalScore;

    Student(const std::string& name, int m) : name(name), scores(m, 0), totalScore(0) {}
};

bool compareByTotal(const Student &a, const Student &b) {
    if (a.totalScore == b.totalScore) {
        return a.name < b.name; // 按字典顺序排序
    }
    return a.totalScore > b.totalScore;
}

bool compareBySubject(const Student &a, const Student &b, int subjectIndex) {
    if (a.scores[subjectIndex] == b.scores[subjectIndex]) {
        return a.name < b.name; // 按字典顺序排序
    }
    return a.scores[subjectIndex] > b.scores[subjectIndex];
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> subjects(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> subjects[i];
    }

    std::vector<Student> students;
    students.reserve(n); // 预先分配足够的空间

    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cin >> name;
        Student student(name, m);
        for (int j = 0; j < m; ++j) {
            std::cin >> student.scores[j];
            student.totalScore += student.scores[j];
        }
        students.push_back(std::move(student));
    }

    std::string sortSubject;
    std::cin >> sortSubject;

    int sortIndex = -1;
    for (int i = 0; i < m; ++i) {
        if (subjects[i] == sortSubject) {
            sortIndex = i;
            break;
        }
    }

    if (sortIndex != -1) {
        std::sort(students.begin(), students.end(), 
                  [sortIndex](const Student &a, const Student &b) {
                      return compareBySubject(a, b, sortIndex);
                  });
    } else {
        std::sort(students.begin(), students.end(), compareByTotal);
    }

    for (const auto &student : students) {
        std::cout << student.name << " ";
        for (int score : student.scores) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
