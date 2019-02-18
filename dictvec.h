#include <map>
#include <type_traits>


template <typename Tk, typename Tv>
class Dictvec {
    std::map<Tk, Tv> m;
    
public:
    Dictvec();
    Dictvec(std::map<Tk, Tv> mm);
    void add(const Tk&, const Tv&);

    Dictvec operator*(const Dictvec&);
    Dictvec operator+(const Dictvec&);

    void display(std::ostream &);

    template <typename FTk, typename FTv, typename Tscale>
    friend Dictvec<FTk, FTv> operator*(const Tscale&, const Dictvec<FTk, FTv>&);

    template <typename FTk, typename FTv, typename Tscale>
    friend Dictvec<FTk, FTv> operator*(const Dictvec<FTk, FTv>&, const Tscale&);    
};

template<typename Tk, typename Tv>
Dictvec<Tk, Tv>::Dictvec(): m() { }

template<typename Tk, typename Tv>
Dictvec<Tk, Tv>::Dictvec(std::map<Tk, Tv> mm): m(mm) { }

template<typename Tk, typename Tv>
void Dictvec<Tk, Tv>::add(const Tk& key, const Tv& val)
{
    m.insert(std::pair<Tk, Tv>(key, val));
}

template<typename Tk, typename Tv>
void Dictvec<Tk, Tv>::display(std::ostream & os)
{
    for(auto it=m.begin(); it!=m.end(); ++it){
	os << it->first << " => " << it->second << "\n";
    }
}

template<typename Tk, typename Tv>
Dictvec<Tk, Tv> Dictvec<Tk, Tv>::operator*(const Dictvec<Tk, Tv>& rv){
    std::map<Tk, Tv> ret;
    for(auto it = m.begin(); it != m.end(); ++it) {
	Tk key = it->first;
	if(rv.m.find(key) != rv.m.end()) {
	    ret[key] = it->second * rv.m.at(key);
	}
    }
    return Dictvec(ret);
}

template<typename Tk, typename Tv>
Dictvec<Tk, Tv> Dictvec<Tk, Tv>::operator+(const Dictvec<Tk, Tv>& rv){
    std::map<Tk, Tv> ret(m);
	
    //for(auto it = m.begin(); it != m.end(); ++it) {
    //    ret[it->first] = it->second;
    //}
    for(auto it = rv.m.begin(); it != rv.m.end(); ++it) {
	ret[it->first] += it->second;
    }
    return Dictvec(ret);
}


template<typename Tk, typename Tv, typename Tscale>
Dictvec<Tk, Tv> operator*(const Tscale& scale, const Dictvec<Tk, Tv>& dv)
{
    std::map<Tk, Tv> ret;
    for(auto it = dv.m.begin(); it != dv.m.end(); ++it) {
	ret[it->first] = scale * it->second;
    }
    return Dictvec<Tk, Tv>(ret);
}

template<typename Tk, typename Tv, typename Tscale>
Dictvec<Tk, Tv> operator*(const Dictvec<Tk, Tv>& dv, const Tscale& scale)
{
    std::map<Tk, Tv> ret;
    for(auto it = dv.m.begin(); it != dv.m.end(); ++it) {
	ret[it->first] = scale * it->second;
    }
    return Dictvec<Tk, Tv>(ret);
}
