#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//クラス(Result)の作成
//クラスに含まれる要素は成績(score)と学修番号(id)
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
	//ファイルの読み込み
	ifstream infile("Student_Score.txt");
	int newScore;
	int newiD;
	//vectorを定義し，格納する
	vector<Result> v;
	size_t s = v.size();
	int i = 0;
	while (infile >> newScore >> newiD) {
		v.emplace_back();
		v[i].setiD(newScore);
		v[i].setScore(newiD);
		i++;
	}
	//イテレータを用いて成績で昇順に並び替える
	sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.score < rhs.score;
		});
	//出力
	for (const auto& result : v) {
		cout << result.id << " " << result.score << endl;
	}
}