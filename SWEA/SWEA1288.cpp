#include<bits/stdc++.h>
using namespace std;

int T;
int target, bits, cnt;

void func(){
	int len = log10(target)+1, pow = 10;
	bits = bits | 1<<(target%pow);
	for(int i=0; i<len-1; i++){
		bits = bits | 1<<((target/pow)%10);
		pow *= 10;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		cin >> target;
		cnt = 1;
		bits = 0;
		func();
		while((bits&(0b1111111111))!=0b1111111111){
			target = (target/cnt) * (cnt+1);
			cnt++;
			func();
		}
		cout << "#" << test_case << " " << target << "\n";
	}
}
