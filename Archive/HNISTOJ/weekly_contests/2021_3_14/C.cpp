#include<iostream>
using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
 	return a*b/gcd(a,b);
}

void dabiao(int in){
    int minn=1;
    int maxx=0;
    for(int i=minn;i<=in;i++){
        for(int j=minn;j<=in;j++){
            for(int k=minn;k<=in;k++){
                if(i!=j&&j!=k&&i!=k){
                    int tmp=lcm(i,j);
                    tmp=lcm(tmp,k);
                    maxx=max(maxx,tmp);
                }
            }
        }
    }
    cout<<"else if(num=="<<in<<") cout<<"<<maxx<<"<<endl;"<<endl;
    return;
}

int main(){
    int num;

    for(int i=4;i<=106;i++) dabiao(i);
    return 0;

    while(cin>>num&&num!=EOF){
        if(num==1) cout<<1<<endl;
        else if(num==2) cout<<2<<endl;
        else if(num==3) cout<<3<<endl;
        else if(num==4) cout<<12<<endl;
        else if(num==5) cout<<60<<endl;
        else if(num==6) cout<<60<<endl;
        else if(num==7) cout<<210<<endl;
        else if(num==8) cout<<280<<endl;
        else if(num==9) cout<<504<<endl;
        else if(num==10) cout<<630<<endl;
        else if(num==11) cout<<990<<endl;
        else if(num==12) cout<<990<<endl;
        else if(num==13) cout<<1716<<endl;
        else if(num==14) cout<<2002<<endl;
        else if(num==15) cout<<2730<<endl;
        else if(num==16) cout<<3120<<endl;
        else if(num==17) cout<<4080<<endl;
        else if(num==18) cout<<4080<<endl;
        else if(num==19) cout<<5814<<endl;
        else if(num==20) cout<<6460<<endl;
        else if(num==21) cout<<7980<<endl;
        else if(num==22) cout<<8778<<endl;
        else if(num==23) cout<<10626<<endl;
        else if(num==24) cout<<10626<<endl;
        else if(num==25) cout<<13800<<endl;
        else if(num==26) cout<<14950<<endl;
        else if(num==27) cout<<17550<<endl;
        else if(num==28) cout<<18900<<endl;
        else if(num==29) cout<<21924<<endl;
        else if(num==30) cout<<21924<<endl;
        else if(num==31) cout<<26970<<endl;
        else if(num==32) cout<<28768<<endl;
        else if(num==33) cout<<32736<<endl;
        else if(num==34) cout<<34782<<endl;
        else if(num==35) cout<<39270<<endl;
        else if(num==36) cout<<39270<<endl;
        else if(num==37) cout<<46620<<endl;
        else if(num==38) cout<<49210<<endl;
        else if(num==39) cout<<54834<<endl;
        else if(num==40) cout<<57720<<endl;
        else if(num==41) cout<<63960<<endl;
        else if(num==42) cout<<63960<<endl;
        else if(num==43) cout<<74046<<endl;
        else if(num==44) cout<<77572<<endl;
        else if(num==45) cout<<85140<<endl;
        else if(num==46) cout<<89010<<endl;
        else if(num==47) cout<<97290<<endl;
        else if(num==48) cout<<97290<<endl;
        else if(num==49) cout<<110544<<endl;
        else if(num==50) cout<<115150<<endl;
        else if(num==51) cout<<124950<<endl;
        else if(num==52) cout<<129948<<endl;
        else if(num==53) cout<<140556<<endl;
        else if(num==54) cout<<140556<<endl;
        else if(num==55) cout<<157410<<endl;
        else if(num==56) cout<<163240<<endl;
        else if(num==57) cout<<175560<<endl;
        else if(num==58) cout<<181830<<endl;
        else if(num==59) cout<<195054<<endl;
        else if(num==60) cout<<195054<<endl;
        else if(num==61) cout<<215940<<endl;
        else if(num==62) cout<<223138<<endl;
        else if(num==63) cout<<238266<<endl;
        else if(num==64) cout<<245952<<endl;
        else if(num==65) cout<<262080<<endl;
        else if(num==66) cout<<262080<<endl;
        else if(num==67) cout<<287430<<endl;
        else if(num==68) cout<<296140<<endl;
        else if(num==69) cout<<314364<<endl;
        else if(num==70) cout<<323610<<endl;
        else if(num==71) cout<<342930<<endl;
        else if(num==72) cout<<342930<<endl;
        else if(num==73) cout<<373176<<endl;
        else if(num==74) cout<<383542<<endl;
        else if(num==75) cout<<405150<<endl;
        else if(num==76) cout<<416100<<endl;
        else if(num==77) cout<<438900<<endl;
        else if(num==78) cout<<438900<<endl;
        else if(num==79) cout<<474474<<endl;
        else if(num==80) cout<<486640<<endl;
        else if(num==81) cout<<511920<<endl;
        else if(num==82) cout<<524718<<endl;
        else if(num==83) cout<<551286<<endl;
        else if(num==84) cout<<551286<<endl;
        else if(num==85) cout<<592620<<endl;
        else if(num==86) cout<<606730<<endl;
        else if(num==87) cout<<635970<<endl;
        else if(num==88) cout<<650760<<endl;
        else if(num==89) cout<<681384<<endl;
        else if(num==90) cout<<681384<<endl;
        else if(num==91) cout<<728910<<endl;
        else if(num==92) cout<<745108<<endl;
        else if(num==93) cout<<778596<<endl;
        else if(num==94) cout<<795522<<endl;
        else if(num==95) cout<<830490<<endl;
        else if(num==96) cout<<830490<<endl;
        else if(num==97) cout<<884640<<endl;
        else if(num==98) cout<<903070<<endl;
        else if(num==99) cout<<941094<<endl;
        else if(num==100) cout<<960300<<endl;
        else if(num==101) cout<<999900<<endl;
        else if(num==102) cout<<999900<<endl;
        else if(num==103) cout<<1061106<<endl;
        else if(num==104) cout<<1081912<<endl;
        else if(num==105) cout<<1124760<<endl;
        else if(num==106) cout<<1146390<<endl;
    }
    return 0;
}