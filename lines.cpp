//mojtaba96
#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second

using namespace std;

double h, w, d, a, COS, SIN, stp, enp, LL, SL;
vector<pair<double, double>> t, v;

int main(){
	cin >> h >> w >> d >> a, enp = w;
	COS = a == 90 ? 0 : cos(a * M_PI / 180);
	SIN = sin(a * M_PI / 180);
	LL = h / SIN;
	SL = LL - 2 * (d / SIN * COS);
	while(stp > 0 - LL * COS){
		stp -= 2 * (d / SIN);
	}
	enp += 2 * (d / SIN);
	while(stp < enp){
		double x = stp;
		double y = 0;
		t.pb({x, y});
		x += LL * COS;
		y += LL * SIN;
		t.pb({x, y});
		x += d * SIN;
		y -= d * COS;
		t.pb({x, y});
		x -= SL * COS;
		y -= SL * SIN;
		t.pb({x, y});
		x += d * SIN;
		y -= d * COS;
		stp = x;
	}
	int i = -1;
	for(auto u : t){
		i++;
		if(u.X >= 0 && u.X <= w && u.Y >= 0 && u.Y <= h){
			v.pb(u);
		}
		if(u.X < 0){
			switch(i%4){
				case 0:{
					if(u.X + LL * COS >= 0){
						u.Y += (0 - u.X) / COS * SIN;
						u.X = 0;
						v.pb(u);
					}
					break;
				}
				case 1:{
					if(u.X + d * SIN >= 0){
						u.Y -= (0 - u.X) / SIN * COS;
						u.X = 0;
						v.pb(u);
					}
					break;
				}
				case 2:{
					break;
				}
				case 3:{
					if(u.X + LL * COS >= 0){
						double y = u.Y + (0 - u.X) / COS * SIN;
						double x = 0;
						v.pb({x, y});
					}
					if(u.X + d * SIN >= 0){
						double y = u.Y - (0 - u.X) / SIN * COS;
						double x = 0;
						v.pb({x, y});
					}
					break;
				}
			}
		}
		else if(u.X > w){
			switch(i%4){
				case 0:{
					if(u.X - d * SIN <= w){
						u.Y -= (w - u.X) / SIN * COS;
						u.X = w;
						v.pb(u);
					}
					break;
				}
				case 1:{
					if(u.X - LL * COS <= w){
						u.Y += (w - u.X) / COS * SIN;
						u.X = w;
						v.pb(u);
					}
					break;
				}
				case 2:{
					if(u.X - d * SIN <= w){
						double y = u.Y - (w - u.X) / SIN * COS;
						double x = w;
						v.pb({x, y});
					}
					if(u.X - LL * COS <= w){
						double y = u.Y + (w - u.X) / COS * SIN;
						double x = w;
						v.pb({x, y});
					}
					break;
				}
				case 3:{
					break;
				}
			}
		}
	}
	for(auto u : v){
		cout << u.X << ", " << u.Y << endl;
	}
}
