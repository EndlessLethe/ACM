#include <iostream>  
#include <cmath>  
#include <cstdio>  
#include <cstring>  
using namespace std;  


long long N, ans, point, i, candy, token, k, tempcandy;
float scores[100000 + 10];
//long long candy[100000 + 10];
long long research(void);
  
int main(){
	
	#ifdef LOCAL
	freopen("input_ScuACM_2015_��봱��Ĵ���ѧACMICPC������ѡ����_F_Candy Problem.txt", "r", stdin);
	#endif
	

	while ((scanf("%lld",&N)) != EOF) {
		for (i=0; i < N; i++) {
			scanf("%f", &scores[i]);
//			candy[i] = 0;
		}
		point = 0;
		ans = 0;
		candy = 0;
		
		while (point != N) {
			if (point + 1 == N) {
				if (scores[point-1] - scores[point] < -0.00005) {//a<b ����������  ��ֱ��+1 
					if (scores[point-1] - scores[point] < -0.00005 && candy == 0 && point != 0) candy++;
					candy++;
					ans += candy;
					point++;
				}
				else if (scores[point-1] - scores[point] > -0.00005 && scores[point-1] - scores[point] < 0.00005) {//a=b
					ans += candy;
					point++;
				}
				else if (scores[point] - scores[point+1] > 0.00005) {
					ans += 1;
					point++;
				}//�����ܳ���������� 
				break;
			} 
			
			if (scores[point] - scores[point+1] < -0.00005) {//a<b ����������  ��ֱ��+1 
				if (scores[point-1] - scores[point] < -0.00005 && candy == 0 && point != 0) candy++;
				candy++;
				ans += candy;
				point++;
			}
			else if (scores[point] - scores[point+1] > -0.00005 && scores[point] - scores[point+1] < 0.00005) {//a=b
				if (point == 0) candy++;
				else if (scores[point] - scores[point+1] < -0.00005 
				         || (scores[point] - scores[point+1] > -0.00005 && scores[point] - scores[point+1] < 0.00005)) {
				    ans += candy;
				}
				
				point++;
			}
			else {//����һ���½����� 
				if (scores[point-1] - scores[point] < -0.00005) {//a<b ������������ 
					tempcandy = ++candy;
					candy = 0;
					token = 0;
					k = research();
					if (token+1 >= tempcandy) {
						ans += k;
						point += token + 1;
					}
					else {
						ans += tempcandy;
//						candy = tempcandy;
						point++;
					}
				}
				else {
					candy = 0;
					token = 0;
					ans += research();
					point += token + 1;
				}

				
			}
		}
		
		printf("%lld\n",ans);  
	}
      
    
    
    return 0;  
} 

long long research(void)
{
	start:
	if (point + token +1 ==N) {
		return (token + 1) * (token + 2) / 2;//���������Ҫ���� 
	}
	if (scores[point+token] - scores[point+token+1] <= 0.00005) {//a<=b���� 
		return (token + 1) * (token + 2) / 2;
		//�ǹ��ݼ���һ����ʽ 
	}
	else if (scores[point+token] - scores[point+token+1] > 0.00005) {//a>b
		token++;
		goto start;
	}
}
