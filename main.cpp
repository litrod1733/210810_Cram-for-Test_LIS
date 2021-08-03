//
// Created by 이인성 on 2021/08/03.
//

#include <iostream>
#include <cstdio>

using namespace std;

struct Subject {
  int time;
  int points;
};

int score[1000][10000];
int N;
int T;
Subject subject[1000];

int main() {
  cin >> N >> T;

  for(int i = 1; i <= N; i++) {
    int t;
    int p;
    scanf("%d%d", &t, &p);
    subject[i] = {t,p};
  }

  score[0][1] = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= T; j++) {
      int ti = subject[i].time;
      int pi = subject[i].points;

      if(ti > j) {
        score[i][j] = score[i-1][j];
      }
      else {
        score[i][j] = max(score[i-1][j], pi+score[i-1][j-ti]);
      }
    }
  }
  cout << score[N][T];
  return 0;
}