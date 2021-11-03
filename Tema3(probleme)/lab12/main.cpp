#include<bits/stdc++.h>
using namespace std;

class Model
{
protected:
    string nume;
    unsigned greutate;
    int an;
    float v_max;
public:

    virtual float calcul_autonomie() = 0;

    Model(string nume = "", unsigned greutate = 0, int an = 0, float v_max = 0): nume(nume),
                                                                                an(an),
                                                                                greutate(greutate),
                                                                            v_max(v_max){}
    inline string getNume(){return nume;}
        inline void set_viteza(float p)
    {
        v_max = v_max*(1+p/100);

    }
          };


class MasinaCFosil : virtual public Model
{
protected:
    string combustibil;
    int capacitate;
public:
    MasinaCFosil(string nume = "", unsigned greutate = 0, int an = 0, float v_max = 0, string combustibil="", int capacitate=0) : Model(nume, greutate, an, v_max),
                                                                                                                                    combustibil(combustibil),
                                                                                                                                    capacitate(capacitate) {};

    float calcul_autonomie()
    {
        return capacitate/sqrt(greutate);
    }
    friend ostream& operator<< (ostream& out, const MasinaCFosil& ob)
    {
        out<<"Masina cu combustibil fosil "<<ob.nume<<" cu greutate "<<ob.greutate<<" din anul "<<ob.an<<" cu viteza "<<ob.v_max<<" pe ";
        out<<ob.combustibil<<" de capacitate "<<ob.capacitate<<"\n";
        return out;
    }

    friend istream& operator>> (istream& in, MasinaCFosil & ob)
    {
        in>>ob.nume;
        in>>ob.greutate;
        in>>ob.an;
        in>>ob.v_max;
        in>>ob.combustibil>>ob.capacitate;
        return in;

    }
};



class MasinaElectrica: virtual public Model {
protected:

    unsigned capacitateB;

public:
    MasinaElectrica(string nume="", unsigned greutate=0, int an=0, float v_max=0, unsigned capacitateB=0):
            Model(nume,greutate,an,v_max),
            capacitateB(capacitateB) {}

    float calcul_autonomie() {
        return static_cast<float>(capacitateB) / (greutate*greutate);
    }

    friend ostream& operator<<(ostream& out, const MasinaElectrica& ob) {
        out<<"Masina electica "<<ob.nume<<" cu greutatea "<<ob.greutate<<" din anul "<<ob.an<<" cu viteza maxima "<<ob.v_max<<" pe "
           <<" de capacitate "<<ob.capacitateB<<"\n";

           return out;
    }

    friend istream& operator>>(istream& in, MasinaElectrica& ob) {
        cout<<"nume:";in>>ob.nume;
        cout<<"greutate:";in>>ob.greutate;
        cout<<"an";in>>ob.an;
        cout<<"viteza";in>>ob.v_max;
        in>>ob.capacitateB;

        return in;
    }

};

class MasinaHibrid: public MasinaCFosil, public MasinaElectrica
{
public:
    MasinaHibrid(string nume = "", unsigned greutate = 0, int an = 0, float v_max = 0, int capacitate=0, unsigned capacitateB=0):
        MasinaCFosil( nume,  greutate ,  an ,  v_max ,"benzina",  capacitate),
        MasinaElectrica(nume ,  greutate , an ,  v_max ,  capacitate)
        {}
    float calcul_autonomie()
    {
       return  MasinaCFosil::calcul_autonomie()+ MasinaElectrica::calcul_autonomie();
    }

    friend ostream& operator<<(ostream& out, const MasinaHibrid& ob) {
        out<<"Masina hibrid "<<ob.nume<<" cu greutatea "<<ob.greutate<<" din anul "<<ob.an<<" cu viteza maxima "<<ob.v_max<<" cu benzina si capacitatea de "<<ob.capacitate
           <<" cu electric de capacitate "<<ob.capacitateB<<"\n";

           return out;
    }

    friend istream& operator>>(istream& in, MasinaHibrid& ob) {
        cout<<"nume:";in>>ob.nume;
        cout<<"greutate:";in>>ob.greutate;
        cout<<"an";in>>ob.an;
        cout<<"viteza";in>>ob.v_max;
        in>>ob.capacitate;
        in>>ob.capacitateB;

        return in;
    }

};
template<class A,class B,class C>
class Triplet
{
    A first;
    B second;
    C third;
public:
    Triplet(){}
    Triplet(A f, B s,C t):first(f),second(s),third(t){}
};
using Data = Triplet<int,int,int>;
class Tranzactie {
private:
    string nume;
    Data data;
    vector<Model*> achizitii;
public:
    Tranzactie(string nume = "", Data data=Data(0,0,0)): nume(nume), data(data) {

    }

    void adaugareMasinaCombustibil(MasinaCFosil a) {
        achizitii.emplace_back(new MasinaCFosil(a));
    }

    void adaugareMasinaElectrica(MasinaElectrica a) {
        achizitii.emplace_back(new MasinaElectrica(a));
    }

    void adaugareMasinaHibrida(MasinaHibrid a) {
        achizitii.emplace_back(new MasinaHibrid(a));
    }

    ~Tranzactie() {
        for(auto& i : achizitii)
            delete i;
        achizitii.clear();
        achizitii.shrink_to_fit();
    }

    Tranzactie& operator = (const Tranzactie& obj) {
        if(this != &obj) {
            this->nume = obj.nume;
            this->data = obj.data;
            vector<Model*> v;
            for(auto& i : this->achizitii)
                delete i;
            achizitii.clear();
            for(auto& i : obj.achizitii) {
                if(MasinaCFosil* j = dynamic_cast<MasinaCFosil*>(i))
                    v.emplace_back(new MasinaCFosil(*j));

                if(MasinaElectrica* j = dynamic_cast<MasinaElectrica*>(i))
                    v.emplace_back(new MasinaElectrica(*j));

                if(MasinaHibrid* j = dynamic_cast<MasinaHibrid*>(i))
                    v.emplace_back(new MasinaHibrid(*j));
            }
        this->achizitii = std::move(v);
        }
        return* this;
    }
    Tranzactie(const Tranzactie& obj)
    {
        this->nume = obj.nume;
            this->data = obj.data;
            for(auto& i : this->achizitii)
                delete i;
            achizitii.clear();
            for(auto& i : obj.achizitii) {
                if(MasinaCFosil* j = dynamic_cast<MasinaCFosil*>(i))
                    this->achizitii.emplace_back(new MasinaCFosil(*j));

                if(MasinaElectrica* j = dynamic_cast<MasinaElectrica*>(i))
                    this->achizitii.emplace_back(new MasinaElectrica(*j));

                if(MasinaHibrid* j = dynamic_cast<MasinaHibrid*>(i))
                    this->achizitii.emplace_back(new MasinaHibrid(*j));
            }
    }
    inline vector<Model*> get_achizitii(){return achizitii;}
};
class Manager
{
    vector <Tranzactie> vec;
    vector <Model*> model;
    static Manager* instance;
    Manager(){};
    Manager(const Manager&) = delete;
    Manager& operator =(const Manager&) = delete;
public:
    static Manager* get_instance()
    {
        if(!instance)
            instance = new Manager;
        return instance;
    }
    void adaugaModel()
    {
        string opt;
        cin>>opt;
        if(opt=="masinaelectrica")
        {
            MasinaElectrica aux;
            cin>>aux;
            model.push_back(new MasinaElectrica(aux));
        }
        else if(opt=="masinafosil")
        {
            MasinaCFosil aux;
            cin>>aux;
            model.push_back(new MasinaCFosil(aux));
        }
        else
        {
            MasinaHibrid aux;
            cin>>aux;
            model.push_back(new MasinaHibrid(aux));
        }
    }
    void adaugaTranzactie()
    {
        int a,b,c;
        cin>>a>>b>>c;
        string nume;
        cin>>nume;
        int n;
        cin>>n;
        Tranzactie t(nume,Data(a,b,c));
        for(int i=0;i<n;i++){
            string opt;
            cin>>opt;
            if(opt=="masina electrica")
            {
                MasinaElectrica aux;
                cin>>aux;
                t.adaugareMasinaElectrica(aux);
            }
            else if(opt=="masina fosil")
            {
                MasinaCFosil aux;
                cin>>aux;
                t.adaugareMasinaCombustibil(aux);
            }
            else
            {
                MasinaHibrid aux;
                cin>>aux;
                t.adaugareMasinaHibrida(aux);
            }
        }
        vec.push_back(t);
    }
    void modelVandut()
    {
        int ma=0;
        string numema="";
	    unordered_map<string,int> H;
        for(auto &tranzactie : vec)
        {
            vector<Model*> ac = tranzactie.get_achizitii();
           for(auto &model : ac)
           {
                H[model->getNume()]++;
                if(H[model->getNume()]>ma)
                {
                    ma=H[model->getNume()];
                    numema=model->getNume();
                }
           }
        }
        cout<<"Cel mai vândut model e "<<numema<<'\n';
	}
    void maxAutonomie()
    {
        int ma=0;
        string numema="";
        for(auto &tranzactie : vec)
        {
            vector<Model*> ac = tranzactie.get_achizitii();
           for(auto &model : ac)
           {
               float autonomie = model->calcul_autonomie();
                if(autonomie>ma)
                {
                    ma=autonomie;
                    numema=model->getNume();
                }
           }
        }
        cout<<"Cel mai vândut model e "<<numema<<'\n';
	}
       void modifica_viteza(string nume, float p)
    {

        for(auto &it:model)
        {
          if(it->getNume() == nume)
          {
              it->set_viteza(p);
          }
        }
    }

};
Manager* Manager::instance = nullptr;
int main() {
    unique_ptr<Manager> m(Manager::get_instance());
    m->adaugaModel();
    return 0;
}
