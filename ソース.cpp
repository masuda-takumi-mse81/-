#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//�N���X(Result)�̍쐬
//�N���X�Ɋ܂܂��v�f�͐���(score)�Ɗw�C�ԍ�(id)
class Result {
public:
	int score;
	int id;
public:
	void setScore(int newScore) { score = newScore; }
	int getScore() { return score; }
	void setiD(int newiD) { id = newiD; }
	int getiD() { return id; }
};

int main() {
	//�t�@�C���̓ǂݍ���
	ifstream infile("Student_Score.txt");
	int newScore;
	int newiD;
	//vector���`���C�i�[����
	vector<Result> v;
	size_t s = v.size();
	int i = 0;
	while (infile >> newScore >> newiD) {
		v.emplace_back();
		v[i].setiD(newScore);
		v[i].setScore(newiD);
		i++;
	}
	//�C�e���[�^��p���Đ��тŏ����ɕ��ёւ���
	sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.score < rhs.score;
		});
	//�o��
	for (const auto& result : v) {
		cout << result.id << " " << result.score << endl;
	}
}