#include "class.h"

#include <chrono>

int main() {
    std::ofstream out("Time.csv");
    out << "File Name,Bubble,Pyramidic,Merge,Std::sort\n";
    // Чтобы проверить, что сортировки работают правильно, данные из 1_data.csv после сортировок будут
    // записаны в соответствующие файлы
    for (int i = 1; i <= 10; i++) {
        std::vector<Employee> employees;
        out << std::to_string(i)+"_data.csv,";
        std::cout << std::to_string(i)+"_data.csv\n";

        // Bubble
        std::cout << "BUBBLE\n";
        employees = readCSV("data/"+std::to_string(i)+"_data.csv");
        auto begin = std::chrono::steady_clock::now();
        bubbleSort(employees);
        auto end = std::chrono::steady_clock::now();
        auto difftime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        if (i == 1) {
            writeCSV("data/1_data_BUBBLE.csv", employees);
        }
        out << difftime.count() << ",";

        // Pyramidic
        std::cout << "PYRAMIDIC\n";
        employees = readCSV("data/"+std::to_string(i)+"_data.csv");
        begin = std::chrono::steady_clock::now();
        heapSort(employees);
        end = std::chrono::steady_clock::now();
        difftime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        if (i == 1) {
           writeCSV("data/1_data_HEAP.csv", employees);
        }
        out << difftime.count() << ",";

        // Merge
        std::cout << "MERGE\n";
        employees = readCSV("data/"+std::to_string(i)+"_data.csv");
        begin = std::chrono::steady_clock::now();
        mergeSort(employees, 0, employees.size() - 1);
        end = std::chrono::steady_clock::now();
        difftime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        if (i == 1) {
            writeCSV("data/1_data_MERGE.csv", employees);
        }
        out << difftime.count() << ",";

        //std::sort
        std::cout << "std::sort\n\n";
        employees = readCSV("data/"+std::to_string(i)+"_data.csv");
        begin = std::chrono::steady_clock::now();
        std::sort(employees.begin(), employees.end());
        end = std::chrono::steady_clock::now();
        difftime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        if (i == 1) {
            writeCSV("data/1_data_SORT.csv", employees);
        }
        out << difftime.count() << "\n";
    }
    out.close();
    return 0;
}