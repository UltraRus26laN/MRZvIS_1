#include <bits/stdc++.h>

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define pr pair<int,int>

using namespace std;

string s0,s1,s2; vector<int> Vans;
int n,m,i,k,p,e,r,x,y,ind[1111],tact,q;

class PV
{
    private:
      vector<pr> V;
      vector<string> S;
    public:
      PV(){}
      void addPair(pr P){ V.p_b(P); S.p_b("000000"); }
      int get1(int I){ return V[I].fi; }
      int get2(int I){ return V[I].se; }
      void set1(int I, int val){ V[I].fi=val; }
      void setStr(int I, string s){ S[I]=s; }
      string getStr(int I){ return S[I]; }
};

string toBin(int w)
{
    int j; string s="";
    for(j=0; j<6; j++)
    {
        if(w%2)s='1'+s;
        else s='0'+s;
        w/=2;
    }
    return s;
}

int toDec(string s)
{
    int j,w=0,c=1;
    for(j=s.size()-1; j>=s.size()-6; j--)
    {
        if(s[j]=='1')w+=c;
        c*=2;
    }
    return w;
}

int main()
{
    cout << "m = ";
    cin >> m;
    n=6; p=6; r=m;

    PV pv;

    for(i=0; i<m; i++)
    {
        cin >> x >> y;
        pv.addPair(m_p(x,y));
        ind[i]=-i-1;
    }

    for(;;)
    {
        tact++;
        cout << endl << "Tact #" << tact << endl << endl;
        for(i=0; i<m; i++)
        {
            ind[i]++;
            if(ind[i]>=0 && ind[i]<p)
            {
                if(!ind[i])
                {
                    cout << "Pair " << i+1 << " from Dec to Bin:" << endl;
                    cout << "            " << pv.get1(i) << " -> " << toBin(pv.get1(i)) << endl;
                    cout << "            " << pv.get2(i) << " -> " << toBin(pv.get2(i)) << endl;
                }

                cout << "Pair " << i+1 << ", bit position " << ind[i]+1 << ": " << pv.getStr(i) << " -> ";


                s0=pv.getStr(i);
                s1=toBin(pv.get1(i));
                s2=toBin(pv.get2(i));

                if(s2[ind[i]]=='0')s1="000000"; q=s1.size();

                for(e=1; e<=s0.size()-q; e++)s1='0'+s1; q=0;

                for(e=s0.size()-1; e>=0; e--)
                {
                    //cout << "e" << e << endl;
                    if(s0[e]=='1')q++;
                    if(s1[e]=='1')q++;
                    if(q%2)s0[e]='1'; else s0[e]='0';
                    if(q>1)q=1; else q=0;
                }
                if(ind[i] && ind[i]<p-1)s0+='0';
                pv.setStr(i,s0);
                cout << s0 << endl;

                if(ind[i]==p-1)
                {
                    cout << "Pair " << i+1 << " from Bin to Dec:" << endl;
                    cout << "            " << pv.getStr(i) << " -> " << toDec(pv.getStr(i)) << endl;
                    Vans.p_b(toDec(pv.getStr(i)));
                    if(i==m-1)
                    {
                        cout << endl << "ANSWER: ";
                        for(e=0; e<Vans.size(); e++)cout << Vans[e] << " ";
                        cout << endl; return 0;
                    }
                }
            }
        }
    }

    return 0;
}
