#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e2+10;
vector<pair<int,int>> ans[N];

void init() {
    ans[1].emplace_back(33,33);
    ans[1].emplace_back(34,33);

    ans[2].emplace_back(32,33);
    ans[2].emplace_back(33,32);
    ans[2].emplace_back(34,34);
    ans[2].emplace_back(35,33);

    ans[3].emplace_back(31,32);
    ans[3].emplace_back(32,33);
    ans[3].emplace_back(33,32);
    ans[3].emplace_back(33,33);
    ans[3].emplace_back(34,33);
    ans[3].emplace_back(34,34);
    ans[3].emplace_back(35,33);
    ans[3].emplace_back(36,34);

    ans[4].emplace_back(31,33);
    ans[4].emplace_back(32,31);
    ans[4].emplace_back(32,33);
    ans[4].emplace_back(33,32);
    ans[4].emplace_back(34,34);
    ans[4].emplace_back(35,33);
    ans[4].emplace_back(35,35);
    ans[4].emplace_back(36,33);

    ans[5].emplace_back(31,31);
    ans[5].emplace_back(31,33);
    ans[5].emplace_back(32,32);
    ans[5].emplace_back(32,33);
    ans[5].emplace_back(33,32);
    ans[5].emplace_back(34,34);
    ans[5].emplace_back(35,33);
    ans[5].emplace_back(35,34);
    ans[5].emplace_back(36,33);
    ans[5].emplace_back(36,35);

    ans[6].emplace_back(30,32);
    ans[6].emplace_back(31,33);
    ans[6].emplace_back(32,31);
    ans[6].emplace_back(32,32);
    ans[6].emplace_back(32,33);
    ans[6].emplace_back(35,33);
    ans[6].emplace_back(35,34);
    ans[6].emplace_back(35,35);
    ans[6].emplace_back(36,33);
    ans[6].emplace_back(37,34);

    ans[7].emplace_back(30,31);
    ans[7].emplace_back(31,32);
    ans[7].emplace_back(31,33);
    ans[7].emplace_back(32,31);
    ans[7].emplace_back(32,32);
    ans[7].emplace_back(35,34);
    ans[7].emplace_back(35,35);
    ans[7].emplace_back(36,33);
    ans[7].emplace_back(36,34);
    ans[7].emplace_back(37,35);

    ans[8].emplace_back(30,32);
    ans[8].emplace_back(31,30);
    ans[8].emplace_back(31,32);
    ans[8].emplace_back(32,31);
    ans[8].emplace_back(32,32);
    ans[8].emplace_back(35,34);
    ans[8].emplace_back(35,35);
    ans[8].emplace_back(36,34);
    ans[8].emplace_back(36,36);
    ans[8].emplace_back(37,34);

    ans[9].emplace_back(30,30);
    ans[9].emplace_back(30,32);
    ans[9].emplace_back(31,31);
    ans[9].emplace_back(31,32);
    ans[9].emplace_back(32,31);
    ans[9].emplace_back(35,35);
    ans[9].emplace_back(36,34);
    ans[9].emplace_back(36,35);
    ans[9].emplace_back(37,34);
    ans[9].emplace_back(37,36);

    ans[10].emplace_back(29,31);
    ans[10].emplace_back(30,32);
    ans[10].emplace_back(31,30);
    ans[10].emplace_back(31,31);
    ans[10].emplace_back(31,32);
    ans[10].emplace_back(36,34);
    ans[10].emplace_back(36,35);
    ans[10].emplace_back(36,36);
    ans[10].emplace_back(37,34);
    ans[10].emplace_back(38,35);

    ans[11].emplace_back(29,30);
    ans[11].emplace_back(30,31);
    ans[11].emplace_back(30,32);
    ans[11].emplace_back(31,30);
    ans[11].emplace_back(31,31);
    ans[11].emplace_back(36,35);
    ans[11].emplace_back(36,36);
    ans[11].emplace_back(37,34);
    ans[11].emplace_back(37,35);
    ans[11].emplace_back(38,36);

    ans[12].emplace_back(29,31);
    ans[12].emplace_back(30,29);
    ans[12].emplace_back(30,31);
    ans[12].emplace_back(31,30);
    ans[12].emplace_back(31,31);
    ans[12].emplace_back(36,35);
    ans[12].emplace_back(36,36);
    ans[12].emplace_back(37,35);
    ans[12].emplace_back(37,37);
    ans[12].emplace_back(38,35);

    ans[13].emplace_back(29,29);
    ans[13].emplace_back(29,31);
    ans[13].emplace_back(30,30);
    ans[13].emplace_back(30,31);
    ans[13].emplace_back(31,30);
    ans[13].emplace_back(36,36);
    ans[13].emplace_back(37,35);
    ans[13].emplace_back(37,36);
    ans[13].emplace_back(38,35);
    ans[13].emplace_back(38,37);

    ans[14].emplace_back(28,30);
    ans[14].emplace_back(29,31);
    ans[14].emplace_back(30,29);
    ans[14].emplace_back(30,30);
    ans[14].emplace_back(30,31);
    ans[14].emplace_back(37,35);
    ans[14].emplace_back(37,36);
    ans[14].emplace_back(37,37);
    ans[14].emplace_back(38,35);
    ans[14].emplace_back(39,36);

    ans[15].emplace_back(28,29);
    ans[15].emplace_back(29,30);
    ans[15].emplace_back(29,31);
    ans[15].emplace_back(30,29);
    ans[15].emplace_back(30,30);
    ans[15].emplace_back(37,36);
    ans[15].emplace_back(37,37);
    ans[15].emplace_back(38,35);
    ans[15].emplace_back(38,36);
    ans[15].emplace_back(39,37);

    ans[16].emplace_back(28,30);
    ans[16].emplace_back(29,28);
    ans[16].emplace_back(29,30);
    ans[16].emplace_back(30,29);
    ans[16].emplace_back(30,30);
    ans[16].emplace_back(37,36);
    ans[16].emplace_back(37,37);
    ans[16].emplace_back(38,36);
    ans[16].emplace_back(38,38);
    ans[16].emplace_back(39,36);

    ans[17].emplace_back(28,28);
    ans[17].emplace_back(28,30);
    ans[17].emplace_back(29,29);
    ans[17].emplace_back(29,30);
    ans[17].emplace_back(30,29);
    ans[17].emplace_back(37,37);
    ans[17].emplace_back(38,36);
    ans[17].emplace_back(38,37);
    ans[17].emplace_back(39,36);
    ans[17].emplace_back(39,38);

    ans[18].emplace_back(27,29);
    ans[18].emplace_back(28,30);
    ans[18].emplace_back(29,28);
    ans[18].emplace_back(29,29);
    ans[18].emplace_back(29,30);
    ans[18].emplace_back(38,36);
    ans[18].emplace_back(38,37);
    ans[18].emplace_back(38,38);
    ans[18].emplace_back(39,36);
    ans[18].emplace_back(40,37);

    ans[19].emplace_back(27,28);
    ans[19].emplace_back(28,29);
    ans[19].emplace_back(28,30);
    ans[19].emplace_back(29,28);
    ans[19].emplace_back(29,29);
    ans[19].emplace_back(38,37);
    ans[19].emplace_back(38,38);
    ans[19].emplace_back(39,36);
    ans[19].emplace_back(39,37);
    ans[19].emplace_back(40,38);

    ans[20].emplace_back(27,29);
    ans[20].emplace_back(28,27);
    ans[20].emplace_back(28,29);
    ans[20].emplace_back(29,28);
    ans[20].emplace_back(29,29);
    ans[20].emplace_back(38,37);
    ans[20].emplace_back(38,38);
    ans[20].emplace_back(39,37);
    ans[20].emplace_back(39,39);
    ans[20].emplace_back(40,37);

    ans[21].emplace_back(27,27);
    ans[21].emplace_back(27,29);
    ans[21].emplace_back(28,28);
    ans[21].emplace_back(28,29);
    ans[21].emplace_back(29,28);
    ans[21].emplace_back(38,38);
    ans[21].emplace_back(39,37);
    ans[21].emplace_back(39,38);
    ans[21].emplace_back(40,37);
    ans[21].emplace_back(40,39);

    ans[22].emplace_back(26,28);
    ans[22].emplace_back(27,29);
    ans[22].emplace_back(28,27);
    ans[22].emplace_back(28,28);
    ans[22].emplace_back(28,29);
    ans[22].emplace_back(39,37);
    ans[22].emplace_back(39,38);
    ans[22].emplace_back(39,39);
    ans[22].emplace_back(40,37);
    ans[22].emplace_back(41,38);

    ans[23].emplace_back(26,27);
    ans[23].emplace_back(27,28);
    ans[23].emplace_back(27,29);
    ans[23].emplace_back(28,27);
    ans[23].emplace_back(28,28);
    ans[23].emplace_back(39,38);
    ans[23].emplace_back(39,39);
    ans[23].emplace_back(40,37);
    ans[23].emplace_back(40,38);
    ans[23].emplace_back(41,39);

    ans[24].emplace_back(26,28);
    ans[24].emplace_back(27,26);
    ans[24].emplace_back(27,28);
    ans[24].emplace_back(28,27);
    ans[24].emplace_back(28,28);
    ans[24].emplace_back(39,38);
    ans[24].emplace_back(39,39);
    ans[24].emplace_back(40,38);
    ans[24].emplace_back(40,40);
    ans[24].emplace_back(41,38);

    ans[25].emplace_back(26,26);
    ans[25].emplace_back(26,28);
    ans[25].emplace_back(27,27);
    ans[25].emplace_back(27,28);
    ans[25].emplace_back(28,27);
    ans[25].emplace_back(39,39);
    ans[25].emplace_back(40,38);
    ans[25].emplace_back(40,39);
    ans[25].emplace_back(41,38);
    ans[25].emplace_back(41,40);

    ans[26].emplace_back(25,27);
    ans[26].emplace_back(26,28);
    ans[26].emplace_back(27,26);
    ans[26].emplace_back(27,27);
    ans[26].emplace_back(27,28);
    ans[26].emplace_back(40,38);
    ans[26].emplace_back(40,39);
    ans[26].emplace_back(40,40);
    ans[26].emplace_back(41,38);
    ans[26].emplace_back(42,39);

    ans[27].emplace_back(25,26);
    ans[27].emplace_back(26,27);
    ans[27].emplace_back(26,28);
    ans[27].emplace_back(27,26);
    ans[27].emplace_back(27,27);
    ans[27].emplace_back(40,39);
    ans[27].emplace_back(40,40);
    ans[27].emplace_back(41,38);
    ans[27].emplace_back(41,39);
    ans[27].emplace_back(42,40);

    ans[28].emplace_back(25,27);
    ans[28].emplace_back(26,25);
    ans[28].emplace_back(26,27);
    ans[28].emplace_back(27,26);
    ans[28].emplace_back(27,27);
    ans[28].emplace_back(40,39);
    ans[28].emplace_back(40,40);
    ans[28].emplace_back(41,39);
    ans[28].emplace_back(41,41);
    ans[28].emplace_back(42,39);

    ans[29].emplace_back(25,25);
    ans[29].emplace_back(25,27);
    ans[29].emplace_back(26,26);
    ans[29].emplace_back(26,27);
    ans[29].emplace_back(27,26);
    ans[29].emplace_back(40,40);
    ans[29].emplace_back(41,39);
    ans[29].emplace_back(41,40);
    ans[29].emplace_back(42,39);
    ans[29].emplace_back(42,41);

    ans[30].emplace_back(24,26);
    ans[30].emplace_back(25,27);
    ans[30].emplace_back(26,25);
    ans[30].emplace_back(26,26);
    ans[30].emplace_back(26,27);
    ans[30].emplace_back(41,39);
    ans[30].emplace_back(41,40);
    ans[30].emplace_back(41,41);
    ans[30].emplace_back(42,39);
    ans[30].emplace_back(43,40);

    ans[31].emplace_back(24,25);
    ans[31].emplace_back(25,26);
    ans[31].emplace_back(25,27);
    ans[31].emplace_back(26,25);
    ans[31].emplace_back(26,26);
    ans[31].emplace_back(41,40);
    ans[31].emplace_back(41,41);
    ans[31].emplace_back(42,39);
    ans[31].emplace_back(42,40);
    ans[31].emplace_back(43,41);

    ans[32].emplace_back(24,26);
    ans[32].emplace_back(25,24);
    ans[32].emplace_back(25,26);
    ans[32].emplace_back(26,25);
    ans[32].emplace_back(26,26);
    ans[32].emplace_back(41,40);
    ans[32].emplace_back(41,41);
    ans[32].emplace_back(42,40);
    ans[32].emplace_back(42,42);
    ans[32].emplace_back(43,40);

    ans[33].emplace_back(24,24);
    ans[33].emplace_back(24,26);
    ans[33].emplace_back(25,25);
    ans[33].emplace_back(25,26);
    ans[33].emplace_back(26,25);
    ans[33].emplace_back(41,41);
    ans[33].emplace_back(42,40);
    ans[33].emplace_back(42,41);
    ans[33].emplace_back(43,40);
    ans[33].emplace_back(43,42);

    ans[34].emplace_back(23,25);
    ans[34].emplace_back(24,26);
    ans[34].emplace_back(25,24);
    ans[34].emplace_back(25,25);
    ans[34].emplace_back(25,26);
    ans[34].emplace_back(42,40);
    ans[34].emplace_back(42,41);
    ans[34].emplace_back(42,42);
    ans[34].emplace_back(43,40);
    ans[34].emplace_back(44,41);

    ans[35].emplace_back(23,24);
    ans[35].emplace_back(24,25);
    ans[35].emplace_back(24,26);
    ans[35].emplace_back(25,24);
    ans[35].emplace_back(25,25);
    ans[35].emplace_back(42,41);
    ans[35].emplace_back(42,42);
    ans[35].emplace_back(43,40);
    ans[35].emplace_back(43,41);
    ans[35].emplace_back(44,42);

    ans[36].emplace_back(23,25);
    ans[36].emplace_back(24,23);
    ans[36].emplace_back(24,25);
    ans[36].emplace_back(25,24);
    ans[36].emplace_back(25,25);
    ans[36].emplace_back(42,41);
    ans[36].emplace_back(42,42);
    ans[36].emplace_back(43,41);
    ans[36].emplace_back(43,43);
    ans[36].emplace_back(44,41);

    ans[37].emplace_back(23,23);
    ans[37].emplace_back(23,25);
    ans[37].emplace_back(24,24);
    ans[37].emplace_back(24,25);
    ans[37].emplace_back(25,24);
    ans[37].emplace_back(42,42);
    ans[37].emplace_back(43,41);
    ans[37].emplace_back(43,42);
    ans[37].emplace_back(44,41);
    ans[37].emplace_back(44,43);

    ans[38].emplace_back(22,24);
    ans[38].emplace_back(23,25);
    ans[38].emplace_back(24,23);
    ans[38].emplace_back(24,24);
    ans[38].emplace_back(24,25);
    ans[38].emplace_back(43,41);
    ans[38].emplace_back(43,42);
    ans[38].emplace_back(43,43);
    ans[38].emplace_back(44,41);
    ans[38].emplace_back(45,42);

    ans[39].emplace_back(22,23);
    ans[39].emplace_back(23,24);
    ans[39].emplace_back(23,25);
    ans[39].emplace_back(24,23);
    ans[39].emplace_back(24,24);
    ans[39].emplace_back(43,42);
    ans[39].emplace_back(43,43);
    ans[39].emplace_back(44,41);
    ans[39].emplace_back(44,42);
    ans[39].emplace_back(45,43);

    ans[40].emplace_back(22,24);
    ans[40].emplace_back(23,22);
    ans[40].emplace_back(23,24);
    ans[40].emplace_back(24,23);
    ans[40].emplace_back(24,24);
    ans[40].emplace_back(43,42);
    ans[40].emplace_back(43,43);
    ans[40].emplace_back(44,42);
    ans[40].emplace_back(44,44);
    ans[40].emplace_back(45,42);

    ans[41].emplace_back(22,22);
    ans[41].emplace_back(22,24);
    ans[41].emplace_back(23,23);
    ans[41].emplace_back(23,24);
    ans[41].emplace_back(24,23);
    ans[41].emplace_back(43,43);
    ans[41].emplace_back(44,42);
    ans[41].emplace_back(44,43);
    ans[41].emplace_back(45,42);
    ans[41].emplace_back(45,44);

    ans[42].emplace_back(21,23);
    ans[42].emplace_back(22,24);
    ans[42].emplace_back(23,22);
    ans[42].emplace_back(23,23);
    ans[42].emplace_back(23,24);
    ans[42].emplace_back(44,42);
    ans[42].emplace_back(44,43);
    ans[42].emplace_back(44,44);
    ans[42].emplace_back(45,42);
    ans[42].emplace_back(46,43);

    ans[43].emplace_back(21,22);
    ans[43].emplace_back(22,23);
    ans[43].emplace_back(22,24);
    ans[43].emplace_back(23,22);
    ans[43].emplace_back(23,23);
    ans[43].emplace_back(44,43);
    ans[43].emplace_back(44,44);
    ans[43].emplace_back(45,42);
    ans[43].emplace_back(45,43);
    ans[43].emplace_back(46,44);

    ans[44].emplace_back(21,23);
    ans[44].emplace_back(22,21);
    ans[44].emplace_back(22,23);
    ans[44].emplace_back(23,22);
    ans[44].emplace_back(23,23);
    ans[44].emplace_back(44,43);
    ans[44].emplace_back(44,44);
    ans[44].emplace_back(45,43);
    ans[44].emplace_back(45,45);
    ans[44].emplace_back(46,43);

    ans[45].emplace_back(21,21);
    ans[45].emplace_back(21,23);
    ans[45].emplace_back(22,22);
    ans[45].emplace_back(22,23);
    ans[45].emplace_back(23,22);
    ans[45].emplace_back(44,44);
    ans[45].emplace_back(45,43);
    ans[45].emplace_back(45,44);
    ans[45].emplace_back(46,43);
    ans[45].emplace_back(46,45);

    ans[46].emplace_back(20,22);
    ans[46].emplace_back(21,23);
    ans[46].emplace_back(22,21);
    ans[46].emplace_back(22,22);
    ans[46].emplace_back(22,23);
    ans[46].emplace_back(45,43);
    ans[46].emplace_back(45,44);
    ans[46].emplace_back(45,45);
    ans[46].emplace_back(46,43);
    ans[46].emplace_back(47,44);

    ans[47].emplace_back(20,21);
    ans[47].emplace_back(21,22);
    ans[47].emplace_back(21,23);
    ans[47].emplace_back(22,21);
    ans[47].emplace_back(22,22);
    ans[47].emplace_back(45,44);
    ans[47].emplace_back(45,45);
    ans[47].emplace_back(46,43);
    ans[47].emplace_back(46,44);
    ans[47].emplace_back(47,45);

    ans[48].emplace_back(20,22);
    ans[48].emplace_back(21,20);
    ans[48].emplace_back(21,22);
    ans[48].emplace_back(22,21);
    ans[48].emplace_back(22,22);
    ans[48].emplace_back(45,44);
    ans[48].emplace_back(45,45);
    ans[48].emplace_back(46,44);
    ans[48].emplace_back(46,46);
    ans[48].emplace_back(47,44);

    ans[49].emplace_back(20,20);
    ans[49].emplace_back(20,22);
    ans[49].emplace_back(21,21);
    ans[49].emplace_back(21,22);
    ans[49].emplace_back(22,21);
    ans[49].emplace_back(45,45);
    ans[49].emplace_back(46,44);
    ans[49].emplace_back(46,45);
    ans[49].emplace_back(47,44);
    ans[49].emplace_back(47,46);

    ans[50].emplace_back(19,21);
    ans[50].emplace_back(20,22);
    ans[50].emplace_back(21,20);
    ans[50].emplace_back(21,21);
    ans[50].emplace_back(21,22);
    ans[50].emplace_back(46,44);
    ans[50].emplace_back(46,45);
    ans[50].emplace_back(46,46);
    ans[50].emplace_back(47,44);
    ans[50].emplace_back(48,45);

    ans[51].emplace_back(19,20);
    ans[51].emplace_back(20,21);
    ans[51].emplace_back(20,22);
    ans[51].emplace_back(21,20);
    ans[51].emplace_back(21,21);
    ans[51].emplace_back(46,45);
    ans[51].emplace_back(46,46);
    ans[51].emplace_back(47,44);
    ans[51].emplace_back(47,45);
    ans[51].emplace_back(48,46);

    ans[52].emplace_back(19,21);
    ans[52].emplace_back(20,19);
    ans[52].emplace_back(20,21);
    ans[52].emplace_back(21,20);
    ans[52].emplace_back(21,21);
    ans[52].emplace_back(46,45);
    ans[52].emplace_back(46,46);
    ans[52].emplace_back(47,45);
    ans[52].emplace_back(47,47);
    ans[52].emplace_back(48,45);

    ans[53].emplace_back(19,19);
    ans[53].emplace_back(19,21);
    ans[53].emplace_back(20,20);
    ans[53].emplace_back(20,21);
    ans[53].emplace_back(21,20);
    ans[53].emplace_back(46,46);
    ans[53].emplace_back(47,45);
    ans[53].emplace_back(47,46);
    ans[53].emplace_back(48,45);
    ans[53].emplace_back(48,47);

    ans[54].emplace_back(18,20);
    ans[54].emplace_back(19,21);
    ans[54].emplace_back(20,19);
    ans[54].emplace_back(20,20);
    ans[54].emplace_back(20,21);
    ans[54].emplace_back(47,45);
    ans[54].emplace_back(47,46);
    ans[54].emplace_back(47,47);
    ans[54].emplace_back(48,45);
    ans[54].emplace_back(49,46);

    ans[55].emplace_back(18,19);
    ans[55].emplace_back(19,20);
    ans[55].emplace_back(19,21);
    ans[55].emplace_back(20,19);
    ans[55].emplace_back(20,20);
    ans[55].emplace_back(47,46);
    ans[55].emplace_back(47,47);
    ans[55].emplace_back(48,45);
    ans[55].emplace_back(48,46);
    ans[55].emplace_back(49,47);

    ans[56].emplace_back(18,20);
    ans[56].emplace_back(19,18);
    ans[56].emplace_back(19,20);
    ans[56].emplace_back(20,19);
    ans[56].emplace_back(20,20);
    ans[56].emplace_back(47,46);
    ans[56].emplace_back(47,47);
    ans[56].emplace_back(48,46);
    ans[56].emplace_back(48,48);
    ans[56].emplace_back(49,46);

    ans[57].emplace_back(18,18);
    ans[57].emplace_back(18,20);
    ans[57].emplace_back(19,19);
    ans[57].emplace_back(19,20);
    ans[57].emplace_back(20,19);
    ans[57].emplace_back(47,47);
    ans[57].emplace_back(48,46);
    ans[57].emplace_back(48,47);
    ans[57].emplace_back(49,46);
    ans[57].emplace_back(49,48);

    ans[58].emplace_back(17,19);
    ans[58].emplace_back(18,20);
    ans[58].emplace_back(19,18);
    ans[58].emplace_back(19,19);
    ans[58].emplace_back(19,20);
    ans[58].emplace_back(48,46);
    ans[58].emplace_back(48,47);
    ans[58].emplace_back(48,48);
    ans[58].emplace_back(49,46);
    ans[58].emplace_back(50,47);

    ans[59].emplace_back(17,18);
    ans[59].emplace_back(18,19);
    ans[59].emplace_back(18,20);
    ans[59].emplace_back(19,18);
    ans[59].emplace_back(19,19);
    ans[59].emplace_back(48,47);
    ans[59].emplace_back(48,48);
    ans[59].emplace_back(49,46);
    ans[59].emplace_back(49,47);
    ans[59].emplace_back(50,48);

    ans[60].emplace_back(17,19);
    ans[60].emplace_back(18,17);
    ans[60].emplace_back(18,19);
    ans[60].emplace_back(19,18);
    ans[60].emplace_back(19,19);
    ans[60].emplace_back(48,47);
    ans[60].emplace_back(48,48);
    ans[60].emplace_back(49,47);
    ans[60].emplace_back(49,49);
    ans[60].emplace_back(50,47);

    ans[61].emplace_back(17,17);
    ans[61].emplace_back(17,19);
    ans[61].emplace_back(18,18);
    ans[61].emplace_back(18,19);
    ans[61].emplace_back(19,18);
    ans[61].emplace_back(48,48);
    ans[61].emplace_back(49,47);
    ans[61].emplace_back(49,48);
    ans[61].emplace_back(50,47);
    ans[61].emplace_back(50,49);

    ans[62].emplace_back(16,18);
    ans[62].emplace_back(17,19);
    ans[62].emplace_back(18,17);
    ans[62].emplace_back(18,18);
    ans[62].emplace_back(18,19);
    ans[62].emplace_back(49,47);
    ans[62].emplace_back(49,48);
    ans[62].emplace_back(49,49);
    ans[62].emplace_back(50,47);
    ans[62].emplace_back(51,48);

    ans[63].emplace_back(16,17);
    ans[63].emplace_back(17,18);
    ans[63].emplace_back(17,19);
    ans[63].emplace_back(18,17);
    ans[63].emplace_back(18,18);
    ans[63].emplace_back(49,48);
    ans[63].emplace_back(49,49);
    ans[63].emplace_back(50,47);
    ans[63].emplace_back(50,48);
    ans[63].emplace_back(51,49);

    ans[64].emplace_back(16,18);
    ans[64].emplace_back(17,16);
    ans[64].emplace_back(17,18);
    ans[64].emplace_back(18,17);
    ans[64].emplace_back(18,18);
    ans[64].emplace_back(49,48);
    ans[64].emplace_back(49,49);
    ans[64].emplace_back(50,48);
    ans[64].emplace_back(50,50);
    ans[64].emplace_back(51,48);

    ans[65].emplace_back(16,16);
    ans[65].emplace_back(16,18);
    ans[65].emplace_back(17,17);
    ans[65].emplace_back(17,18);
    ans[65].emplace_back(18,17);
    ans[65].emplace_back(49,49);
    ans[65].emplace_back(50,48);
    ans[65].emplace_back(50,49);
    ans[65].emplace_back(51,48);
    ans[65].emplace_back(51,50);

    ans[66].emplace_back(15,17);
    ans[66].emplace_back(16,18);
    ans[66].emplace_back(17,16);
    ans[66].emplace_back(17,17);
    ans[66].emplace_back(17,18);
    ans[66].emplace_back(50,48);
    ans[66].emplace_back(50,49);
    ans[66].emplace_back(50,50);
    ans[66].emplace_back(51,48);
    ans[66].emplace_back(52,49);

    ans[67].emplace_back(15,16);
    ans[67].emplace_back(16,17);
    ans[67].emplace_back(16,18);
    ans[67].emplace_back(17,16);
    ans[67].emplace_back(17,17);
    ans[67].emplace_back(50,49);
    ans[67].emplace_back(50,50);
    ans[67].emplace_back(51,48);
    ans[67].emplace_back(51,49);
    ans[67].emplace_back(52,50);

    ans[68].emplace_back(15,17);
    ans[68].emplace_back(16,15);
    ans[68].emplace_back(16,17);
    ans[68].emplace_back(17,16);
    ans[68].emplace_back(17,17);
    ans[68].emplace_back(50,49);
    ans[68].emplace_back(50,50);
    ans[68].emplace_back(51,49);
    ans[68].emplace_back(51,51);
    ans[68].emplace_back(52,49);

    ans[69].emplace_back(15,15);
    ans[69].emplace_back(15,17);
    ans[69].emplace_back(16,16);
    ans[69].emplace_back(16,17);
    ans[69].emplace_back(17,16);
    ans[69].emplace_back(50,50);
    ans[69].emplace_back(51,49);
    ans[69].emplace_back(51,50);
    ans[69].emplace_back(52,49);
    ans[69].emplace_back(52,51);

    ans[70].emplace_back(14,16);
    ans[70].emplace_back(15,17);
    ans[70].emplace_back(16,15);
    ans[70].emplace_back(16,16);
    ans[70].emplace_back(16,17);
    ans[70].emplace_back(51,49);
    ans[70].emplace_back(51,50);
    ans[70].emplace_back(51,51);
    ans[70].emplace_back(52,49);
    ans[70].emplace_back(53,50);

    ans[71].emplace_back(14,15);
    ans[71].emplace_back(15,16);
    ans[71].emplace_back(15,17);
    ans[71].emplace_back(16,15);
    ans[71].emplace_back(16,16);
    ans[71].emplace_back(51,50);
    ans[71].emplace_back(51,51);
    ans[71].emplace_back(52,49);
    ans[71].emplace_back(52,50);
    ans[71].emplace_back(53,51);

    ans[72].emplace_back(14,16);
    ans[72].emplace_back(15,14);
    ans[72].emplace_back(15,16);
    ans[72].emplace_back(16,15);
    ans[72].emplace_back(16,16);
    ans[72].emplace_back(51,50);
    ans[72].emplace_back(51,51);
    ans[72].emplace_back(52,50);
    ans[72].emplace_back(52,52);
    ans[72].emplace_back(53,50);

    ans[73].emplace_back(14,14);
    ans[73].emplace_back(14,16);
    ans[73].emplace_back(15,15);
    ans[73].emplace_back(15,16);
    ans[73].emplace_back(16,15);
    ans[73].emplace_back(51,51);
    ans[73].emplace_back(52,50);
    ans[73].emplace_back(52,51);
    ans[73].emplace_back(53,50);
    ans[73].emplace_back(53,52);

    ans[74].emplace_back(13,15);
    ans[74].emplace_back(14,16);
    ans[74].emplace_back(15,14);
    ans[74].emplace_back(15,15);
    ans[74].emplace_back(15,16);
    ans[74].emplace_back(52,50);
    ans[74].emplace_back(52,51);
    ans[74].emplace_back(52,52);
    ans[74].emplace_back(53,50);
    ans[74].emplace_back(54,51);

    ans[75].emplace_back(13,14);
    ans[75].emplace_back(14,15);
    ans[75].emplace_back(14,16);
    ans[75].emplace_back(15,14);
    ans[75].emplace_back(15,15);
    ans[75].emplace_back(52,51);
    ans[75].emplace_back(52,52);
    ans[75].emplace_back(53,50);
    ans[75].emplace_back(53,51);
    ans[75].emplace_back(54,52);

    ans[76].emplace_back(13,15);
    ans[76].emplace_back(14,13);
    ans[76].emplace_back(14,15);
    ans[76].emplace_back(15,14);
    ans[76].emplace_back(15,15);
    ans[76].emplace_back(52,51);
    ans[76].emplace_back(52,52);
    ans[76].emplace_back(53,51);
    ans[76].emplace_back(53,53);
    ans[76].emplace_back(54,51);

    ans[77].emplace_back(13,13);
    ans[77].emplace_back(13,15);
    ans[77].emplace_back(14,14);
    ans[77].emplace_back(14,15);
    ans[77].emplace_back(15,14);
    ans[77].emplace_back(52,52);
    ans[77].emplace_back(53,51);
    ans[77].emplace_back(53,52);
    ans[77].emplace_back(54,51);
    ans[77].emplace_back(54,53);

    ans[78].emplace_back(12,14);
    ans[78].emplace_back(13,15);
    ans[78].emplace_back(14,13);
    ans[78].emplace_back(14,14);
    ans[78].emplace_back(14,15);
    ans[78].emplace_back(53,51);
    ans[78].emplace_back(53,52);
    ans[78].emplace_back(53,53);
    ans[78].emplace_back(54,51);
    ans[78].emplace_back(55,52);

    ans[79].emplace_back(12,13);
    ans[79].emplace_back(13,14);
    ans[79].emplace_back(13,15);
    ans[79].emplace_back(14,13);
    ans[79].emplace_back(14,14);
    ans[79].emplace_back(53,52);
    ans[79].emplace_back(53,53);
    ans[79].emplace_back(54,51);
    ans[79].emplace_back(54,52);
    ans[79].emplace_back(55,53);

    ans[80].emplace_back(12,14);
    ans[80].emplace_back(13,12);
    ans[80].emplace_back(13,14);
    ans[80].emplace_back(14,13);
    ans[80].emplace_back(14,14);
    ans[80].emplace_back(53,52);
    ans[80].emplace_back(53,53);
    ans[80].emplace_back(54,52);
    ans[80].emplace_back(54,54);
    ans[80].emplace_back(55,52);

    ans[81].emplace_back(12,12);
    ans[81].emplace_back(12,14);
    ans[81].emplace_back(13,13);
    ans[81].emplace_back(13,14);
    ans[81].emplace_back(14,13);
    ans[81].emplace_back(53,53);
    ans[81].emplace_back(54,52);
    ans[81].emplace_back(54,53);
    ans[81].emplace_back(55,52);
    ans[81].emplace_back(55,54);

    ans[82].emplace_back(11,13);
    ans[82].emplace_back(12,14);
    ans[82].emplace_back(13,12);
    ans[82].emplace_back(13,13);
    ans[82].emplace_back(13,14);
    ans[82].emplace_back(54,52);
    ans[82].emplace_back(54,53);
    ans[82].emplace_back(54,54);
    ans[82].emplace_back(55,52);
    ans[82].emplace_back(56,53);

    ans[83].emplace_back(11,12);
    ans[83].emplace_back(12,13);
    ans[83].emplace_back(12,14);
    ans[83].emplace_back(13,12);
    ans[83].emplace_back(13,13);
    ans[83].emplace_back(54,53);
    ans[83].emplace_back(54,54);
    ans[83].emplace_back(55,52);
    ans[83].emplace_back(55,53);
    ans[83].emplace_back(56,54);

    ans[84].emplace_back(11,13);
    ans[84].emplace_back(12,11);
    ans[84].emplace_back(12,13);
    ans[84].emplace_back(13,12);
    ans[84].emplace_back(13,13);
    ans[84].emplace_back(54,53);
    ans[84].emplace_back(54,54);
    ans[84].emplace_back(55,53);
    ans[84].emplace_back(55,55);
    ans[84].emplace_back(56,53);

    ans[85].emplace_back(11,11);
    ans[85].emplace_back(11,13);
    ans[85].emplace_back(12,12);
    ans[85].emplace_back(12,13);
    ans[85].emplace_back(13,12);
    ans[85].emplace_back(54,54);
    ans[85].emplace_back(55,53);
    ans[85].emplace_back(55,54);
    ans[85].emplace_back(56,53);
    ans[85].emplace_back(56,55);

    ans[86].emplace_back(10,12);
    ans[86].emplace_back(11,13);
    ans[86].emplace_back(12,11);
    ans[86].emplace_back(12,12);
    ans[86].emplace_back(12,13);
    ans[86].emplace_back(55,53);
    ans[86].emplace_back(55,54);
    ans[86].emplace_back(55,55);
    ans[86].emplace_back(56,53);
    ans[86].emplace_back(57,54);

    ans[87].emplace_back(10,11);
    ans[87].emplace_back(11,12);
    ans[87].emplace_back(11,13);
    ans[87].emplace_back(12,11);
    ans[87].emplace_back(12,12);
    ans[87].emplace_back(55,54);
    ans[87].emplace_back(55,55);
    ans[87].emplace_back(56,53);
    ans[87].emplace_back(56,54);
    ans[87].emplace_back(57,55);

    ans[88].emplace_back(10,12);
    ans[88].emplace_back(11,10);
    ans[88].emplace_back(11,12);
    ans[88].emplace_back(12,11);
    ans[88].emplace_back(12,12);
    ans[88].emplace_back(55,54);
    ans[88].emplace_back(55,55);
    ans[88].emplace_back(56,54);
    ans[88].emplace_back(56,56);
    ans[88].emplace_back(57,54);

    ans[89].emplace_back(10,10);
    ans[89].emplace_back(10,12);
    ans[89].emplace_back(11,11);
    ans[89].emplace_back(11,12);
    ans[89].emplace_back(12,11);
    ans[89].emplace_back(55,55);
    ans[89].emplace_back(56,54);
    ans[89].emplace_back(56,55);
    ans[89].emplace_back(57,54);
    ans[89].emplace_back(57,56);

    ans[90].emplace_back(9,11);
    ans[90].emplace_back(10,12);
    ans[90].emplace_back(11,10);
    ans[90].emplace_back(11,11);
    ans[90].emplace_back(11,12);
    ans[90].emplace_back(56,54);
    ans[90].emplace_back(56,55);
    ans[90].emplace_back(56,56);
    ans[90].emplace_back(57,54);
    ans[90].emplace_back(58,55);

    ans[91].emplace_back(9,10);
    ans[91].emplace_back(10,11);
    ans[91].emplace_back(10,12);
    ans[91].emplace_back(11,10);
    ans[91].emplace_back(11,11);
    ans[91].emplace_back(56,55);
    ans[91].emplace_back(56,56);
    ans[91].emplace_back(57,54);
    ans[91].emplace_back(57,55);
    ans[91].emplace_back(58,56);

    ans[92].emplace_back(9,11);
    ans[92].emplace_back(10,9);
    ans[92].emplace_back(10,11);
    ans[92].emplace_back(11,10);
    ans[92].emplace_back(11,11);
    ans[92].emplace_back(56,55);
    ans[92].emplace_back(56,56);
    ans[92].emplace_back(57,55);
    ans[92].emplace_back(57,57);
    ans[92].emplace_back(58,55);

    ans[93].emplace_back(9,9);
    ans[93].emplace_back(9,11);
    ans[93].emplace_back(10,10);
    ans[93].emplace_back(10,11);
    ans[93].emplace_back(11,10);
    ans[93].emplace_back(56,56);
    ans[93].emplace_back(57,55);
    ans[93].emplace_back(57,56);
    ans[93].emplace_back(58,55);
    ans[93].emplace_back(58,57);

    ans[94].emplace_back(8,10);
    ans[94].emplace_back(9,11);
    ans[94].emplace_back(10,9);
    ans[94].emplace_back(10,10);
    ans[94].emplace_back(10,11);
    ans[94].emplace_back(57,55);
    ans[94].emplace_back(57,56);
    ans[94].emplace_back(57,57);
    ans[94].emplace_back(58,55);
    ans[94].emplace_back(59,56);

    ans[95].emplace_back(8,9);
    ans[95].emplace_back(9,10);
    ans[95].emplace_back(9,11);
    ans[95].emplace_back(10,9);
    ans[95].emplace_back(10,10);
    ans[95].emplace_back(57,56);
    ans[95].emplace_back(57,57);
    ans[95].emplace_back(58,55);
    ans[95].emplace_back(58,56);
    ans[95].emplace_back(59,57);

    ans[96].emplace_back(8,10);
    ans[96].emplace_back(9,8);
    ans[96].emplace_back(9,10);
    ans[96].emplace_back(10,9);
    ans[96].emplace_back(10,10);
    ans[96].emplace_back(57,56);
    ans[96].emplace_back(57,57);
    ans[96].emplace_back(58,56);
    ans[96].emplace_back(58,58);
    ans[96].emplace_back(59,56);

    ans[97].emplace_back(8,8);
    ans[97].emplace_back(8,10);
    ans[97].emplace_back(9,9);
    ans[97].emplace_back(9,10);
    ans[97].emplace_back(10,9);
    ans[97].emplace_back(57,57);
    ans[97].emplace_back(58,56);
    ans[97].emplace_back(58,57);
    ans[97].emplace_back(59,56);
    ans[97].emplace_back(59,58);

    ans[98].emplace_back(7,9);
    ans[98].emplace_back(8,10);
    ans[98].emplace_back(9,8);
    ans[98].emplace_back(9,9);
    ans[98].emplace_back(9,10);
    ans[98].emplace_back(58,56);
    ans[98].emplace_back(58,57);
    ans[98].emplace_back(58,58);
    ans[98].emplace_back(59,56);
    ans[98].emplace_back(60,57);

    ans[99].emplace_back(7,8);
    ans[99].emplace_back(8,9);
    ans[99].emplace_back(8,10);
    ans[99].emplace_back(9,8);
    ans[99].emplace_back(9,9);
    ans[99].emplace_back(58,57);
    ans[99].emplace_back(58,58);
    ans[99].emplace_back(59,56);
    ans[99].emplace_back(59,57);
    ans[99].emplace_back(60,58);

    ans[100].emplace_back(7,9);
    ans[100].emplace_back(8,7);
    ans[100].emplace_back(8,9);
    ans[100].emplace_back(9,8);
    ans[100].emplace_back(9,9);
    ans[100].emplace_back(58,57);
    ans[100].emplace_back(58,58);
    ans[100].emplace_back(59,57);
    ans[100].emplace_back(59,59);
    ans[100].emplace_back(60,57);
}

void solve() {
    int k;
    cin>>k;
    cout<<ans[k].size()<<endl;
    for(auto [x,y]:ans[k]) cout<<x<<' '<<y<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    solve();
    return 0;
}