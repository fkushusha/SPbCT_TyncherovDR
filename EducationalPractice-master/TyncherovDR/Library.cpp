#include "Library.h"

void writeToSortFile(const std::vector<char>& vector) //������� ��� ������ ������� � ��������������� ����
{
	std::ofstream file2("Sorted.txt", std::ios::app); //�������� �����
	copy(vector.begin(), vector.end(), std::ostream_iterator<char>(file2, " ")); //������ ������� � ����
	file2 << std::endl; //������ �������� ������
	file2.close(); //�������� �����
}
