#include <map>
#include <string>


namespace cpp_css{
class Root{
  public:
    std::map<std::string, std::map<std::string, std::string>> db;
    void add(std::map<std::string, std::map<std::string, std::string>> in_){
        for(const auto& [name, group] : in_)
            for(const auto& [key, value] : group)
                this->db[name][key] = value;
    };

    std::string get(std::string name_, std::string key_){
        if(this->checkExist(name_,key_) == false)
            return "";
        return this->db[name_][key_];
    };
    bool checkExist(std::string name_, std::string key_){
         if(this->checkExistName(name_) == false)
             return false;
         return this->db[name_].find(key_) != this->db[name_].end();
    };
    bool checkExistName(std::string name_){
         return this->db.find(name_) != this->db.end();
    };
    std::string toString(){
        std::string out = "";
        for(const auto& [name, group] : this->db){
            out += name+"{";
            for(const auto& [key, value] : group)
                out += key+":"+value+";";
            out += "}";
        }
        return out;
    };
    std::string toString(std::string name_){
         if(this->checkExistName(name_) == false)
             return "";
        std::string out = "";
        for(const auto& [key, value] : this->db[name_])
            out += key+":"+value+";";
        return out;
    };

};
std::string toString(std::map<std::string, std::string> in_){
    std::string out = "";
    for(const auto& [key, value] : in_)
        out += key+":"+value+";";
    return out;
};
}
