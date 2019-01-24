#include <iostream>
#include "master_control.h"
#include <map>
#include <vector>

using namespace std;


class test_argument_class
{
public:
    test_argument_class(){}
    ~test_argument_class(){}
};

void release_memory(std::map<std::string,void *> &args)
{

    delete (static_cast<string *>(args["string_1"]));

//    std::map<std::string,void *>::iterator it = args.begin();

//    while(it != args.end())
//    {
//        delete it->second;
//        it++;
    //}
}

void add_string_value_1(std::map<std::string, void *> &args)
{
    string aa = "Quarta string";
    *(static_cast<string *> (args["string_4"])) = aa;
}

void add_string_value_2(std::map<std::string, void *> &args)
{

    /*
     * O endereço salvo em args é o da variável aa, dentro da função, o endereço armazena
     * o valor "Quinta string", porém quando ao fim da execução da função,a variável
     * aa é "destruida", ou seja, o valor que estava armazenado nela não existe mais, porém
     * o endereço salvo em args ainda está lá, mas agora com algum valor "lixo" do sistema
     */

    string aa = "Quinta string";
    args["string_5"] = &aa;
}

void print_hash_values(std::map<std::string, void *> &args)
{

    for(std::size_t i=0 ; i< static_cast<vector<int>*>(args["vector"])->size(); i++ )
    {
        std::cout << " " << (*(static_cast<vector<int>*>(args["vector"])))[i]; //->at(i); //Como imprimir com o operador []?
    }

    std::cout << "\n";
    cout << *(static_cast<string *>(args["string_1"])) << "\n";
    cout << *(static_cast<string *>(args["string_2"])) << "\n";
    cout << *(static_cast<string *>(args["string_3"])) << "\n";
    cout << *(static_cast<string *>(args["string_4"])) << "\n";
    cout << *(static_cast<string *>(args["string_5"])) << "\n";
}

int main()
{

    //Supondo que "main" é o view

    std::map<std::string, void *> args; //mapa que pode ter "qualquer" valor, desde que os cast sejam realizados

    args["vector"]              = new vector<int>;
    args["string_1"]            = new string;
    args["string_2"]            = new string;
    args["string_3"]            = new string("Terceira string: no construtor");
    args["string_4"]            = new string;
    args["string_5"]            = new string;
    args["vector<vector<int>>"] = new vector<vector<int>>;
    args["class"] = (new test_argument_class()); //Por que esta classe não dá certo?


   //Atribuindo valores:
   //vector
   (static_cast<vector<int>*> (args["vector"]))->push_back(1); //Por que com o vector não precisa do * e com a string precisa?
   (static_cast<vector<int>*> (args["vector"]))->push_back(2);
   (static_cast<vector<int>*> (args["vector"]))->push_back(3);


    ///////////////////////////////////Atribuindo valores://////////////////////////////////////////////////////

    //vector<vector<int>>
    vector<vector<int>> a;
    vector<int> b;

    //vector<vector<int>>
   ( static_cast<vector<vector<int>>*> (args["vector<vector<int>>"]) )->push_back(vector<int>(10));
    for(size_t i=0; i<( static_cast<vector<vector<int>> *> (args["vector<vector<int>>"]) )->size();i++)
    {
        b.push_back( i );
         (*static_cast<vector<vector<int>>*> (args["vector<vector<int>>"])).push_back( b );
    }



   //string 1
   *(static_cast<string*> (args["string_1"])) = "Primeira string";

    //string 2
    string s1 = "Segunda string";
    string *p_s1 = &s1;
    //static_cast<string *>(args["string_2"]) = &s1; //Porque não posso fazer isso?
    args["string_2"] = static_cast<void *>(&s1);
    p_s1 = static_cast<string *>(args["string_2"]);


    add_string_value_1(args);
    add_string_value_2(args);

    print_hash_values(args);

    return 0;
}
