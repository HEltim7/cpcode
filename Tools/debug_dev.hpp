/**
 * dig()关键字，用来将变量名替换成值
 * debug(arr[dig(j)][dig(j)])
 * rng()关键字，用来指示区间  //可选
*/

#include<iostream>

namespace debug {

    using namespace std;

    int MAXSIZE = 100;  //max output size
    ostream &os = cerr; //default ostream

    struct Stream {

        template<typename T> 
        void output_impl(const T &var) {
#ifndef write
            os << var;
#else
            write(var);
#endif
        }

        template<typename... T> 
        void output(const T&... vars) { (output_impl(vars),...); }

        void endline() {
#ifndef write
            os << endl;
#else
            write('\n');
#endif
        }

    } static stream;


    struct NameLogger {

        bool pipe_line;
        char chpair[1<<7];

        NameLogger() {
            chpair['(' ] = ')' ;
            chpair['[' ] = ']' ;
            chpair['{' ] = '}' ;
            chpair['<' ] = '>' ;
            chpair['\"'] = '\"';
            chpair['\''] = '\'';
        }

        void next_comma(string &s, int &idx, bool silent = 0) {
            while(idx < s.size() && s[idx] != ',') {
                if(!silent) stream.output(s[idx]);
                if(chpair[s[idx]]) {
                    int cnt = 1;
                    char l = s[idx];
                    char r = chpair[l];
                    while(++idx < s.size() && cnt) {
                        if(s[idx] == r) cnt--;
                        else if(s[idx] == l) cnt++;
                        if(!silent) stream.output(s[idx]);
                    }
                }
                else idx++;
            }
            idx++;
        }

        void print(string &s, int &idx, int l = -1, int r = -1) {
            if(pipe_line) stream.output(" | "), pipe_line = 0;
            next_comma(s,idx);
            if(r != -1) {
                stream.output('[',l,"->",r,']');
                next_comma(s,idx,1);next_comma(s,idx,1);
            }
            stream.output(" = ");
        }

        ~NameLogger() { stream.endline(); stream.output("--- end of debugging log ---"); }

    } static logn = NameLogger();

    
    struct ValueLogger {
        
        template<typename T> void
        print(const T &var) { stream.output(var); }

        template<typename T, int Nm> void
        print(const T (&p)[Nm], int l, int r) {
            bool flag = 0;
            if(r - l + 1 > MAXSIZE) r = l + MAXSIZE - 1, flag = 1;
            stream.output('[');
            for(int i = l; i < r; i++) {
                print(p[i]);
                stream.output(',');
            }
            print(p[r]);
            stream.output(flag ? "...]" : "]");
        }

        template<typename T, typename U> void
        print(const pair<T,U> &var) {
            stream.output('(');
            print(var.first);
            stream.output(',');
            print(var.second);
            stream.output(')');
        }

#ifdef _GLIBCXX_TUPLE
        template<class Tuple, size_t... Is>
        void tuple_expand(const Tuple &var, index_sequence<Is...>) {
            ((stream.output(Is == 0 ? "":","), print(get<Is>(var))), ...);
        }

        template<typename... T> void
        print(const tuple<T...> &var) {
            stream.output('(');
            tuple_expand(var, index_sequence_for<T...>{});
            stream.output(')');
        }
#endif

#ifdef _GLIBCXX_VECTOR
        template<typename... T> void
        print(const vector<T...> &var, int l, int r) {
            if(var.empty()) { stream.output("[]"); return;}
            bool flag = 0;
            if(r - l + 1 > MAXSIZE) r = l + MAXSIZE - 1, flag = 1;
            stream.output('[');
            for(int i = l; i < r; i++) {
                print(var[i]);
                stream.output(',');
            }
            print(var[r]);
            stream.output(flag ? "...]" : "]");
        }

        template<typename... T> void
        print(const vector<T...> &var) { print(var, 0, var.size()-1); }
#endif

        template<class T> void
        print_impl_stl(const T &var,const char lc, const char rc) {
            stream.output(lc);
            bool flag = var.size() > MAXSIZE;
            auto end = var.size() > MAXSIZE ? next(var.begin(),MAXSIZE) : var.end();
            for(auto i = var.begin(); i != end; i=next(i)) {
                stream.output(i == var.begin() ? "" : ",");
                print(*i);
            }
            stream.output(flag ? "..." : "");
            stream.output(rc);
        }


#ifdef _GLIBCXX_DEQUE
        template<typename... T> void
        print(const deque<T...> &dq) { print_impl_stl(dq,'<','>'); }
#endif
        
#ifdef _GLIBCXX_SET
        template<typename... T> void
        print(const set<T...> &st) { print_impl_stl(st,'{','}'); }

        template<typename... T> void
        print(const multiset<T...> &st) { print_impl_stl(st,'{','}'); }
#endif

#ifdef _GLIBCXX_UNORDERED_SET
        template<typename... T> void
        print(const unordered_set<T...> &st) { print_impl_stl(st,'{','}'); }
#endif

        template<class T> void
        print_impl_map(const T &mp) {
            stream.output('{');
            bool flag = mp.size() > MAXSIZE;
            auto end = mp.size() > MAXSIZE ? next(mp.begin(),MAXSIZE) : mp.end();
            for(auto i = mp.begin(); i != end; i=next(i)) {
                stream.output (i == mp.begin() ? "" : ",");
                stream.output('{');
                print(i->first);
                stream.output(':');
                print(i->second);
                stream.output('}');
            }
            stream.output(flag ? "...}" : "}");
        }

#ifdef _GLIBCXX_MAP
        template<typename... T> void
        print(const map<T...> &mp) { print_impl_map(mp); }

        template<typename... T> void
        print(const multimap<T...> &mp) { print_impl_map(mp); }
#endif

#ifdef _GLIBCXX_UNORDERED_MAP
        template<typename... T> void
        print(const unordered_map<T...> &mp) { print_impl_map(mp); }
#endif

#ifdef _GLIBCXX_QUEUE
        template<typename... T> void
        print(queue<T...> q) {
            stream.output('<');
            for(int i = 1; !q.empty() && i <= MAXSIZE; i++, q.pop()) {
                stream.output (i == 1 ? "" : ",");
                print(q.front());
            }
            stream.output(q.empty() ? ">" : "...>");
        }

        template<typename... T> void
        print(priority_queue<T...> q) {
            stream.output('<');
            for(int i = 1; !q.empty() && i <= MAXSIZE; i++, q.pop()) {
                stream.output (i == 1 ? "" : ",");
                print(q.top());
            }
            stream.output(q.empty() ? ">" : "...>");
        }
#endif

    } static logv;


    struct Unpacker {

        void unpack(string name, int idx) { logn.pipe_line = 0, stream.endline(); }

        template<typename T> void
        unpack(string name, int idx, const T &var) {
            logn.print(name,idx);
            logv.print(var);
            stream.endline();
        }

        template<typename T, typename... U> void
        unpack(string name, int idx, const T &var, const U&... vars) {
            logn.print(name,idx);
            logv.print(var);
            logn.pipe_line = 1;
            unpack(name, idx, vars...);
        }

        template<typename T, int Nm> void
        unpack(string name, int idx, const T (&p)[Nm]) {
            logn.print(name,idx);
            logv.print(p,0,Nm-1);
            stream.endline();
        }

        template<typename T, typename... U, int Nm> void
        unpack(string name, int idx, const T (&p)[Nm], int l, int r, const U&... vars) {
            if(r == -1) r = Nm-1;
            logn.print(name,idx,l,r);
            logv.print(p,l,r);
            logn.pipe_line = 1;
            unpack(name, idx, vars...);
        }

#ifdef _GLIBCXX_VECTOR
        template<typename... T> void
        unpack(string name, int idx, const vector<T...> &var) {
            logn.print(name,idx);
            logv.print(var,0,var.size()-1);
            stream.endline();
        }

        template<typename... T, typename... U> void
        unpack(string name, int idx, const vector<T...> &var, int l, int r, const U&... vars) {
            logn.print(name,idx,l,r);
            logv.print(var,l,r);
            logn.pipe_line = 1;
            unpack(name, idx, vars...);
        }
#endif

        // template<typename... T> void
        // parse(string name, int idx,const T&... vars) {

        // }

    } static unpacker;
    
} // namespace debug

#define debug(...) debug::unpacker.unpack("[debug] "#__VA_ARGS__, 0 __VA_OPT__(,) __VA_ARGS__)