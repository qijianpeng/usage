/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * @author QI-Jianpeng
 * @version 0.1
 * 
 * @copyright Copyright (c) 2020
 * 
 * Requirement: Install the RapidJSON(https://github.com/Tencent/rapidjson) into your `include` lib.
 * Steps:
 * \code{.sh}
     git clone https://github.com/Tencent/rapidjson.git 
     cd rapidjson/
     git submodule update --init
     mkdir build
     cd build
     cmake ..
     make
     make install
 * \endcode
 */

#include <rapidjson/rapidjson.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h" // for stringify JSON
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <stdexcept>
#include <map>

// #include "ndn-cxx/encoding/block-helpers.hpp"
// #include "file-type.hpp"
/**
 * \brief Macro for steady property access.
 * 
 */
// #define PROPERTY_ACCESSOR_DEFINE(type, propertyName, repidAtomType) \
//   type propertyName ## repidAtomType ## PropertyValue(void) {                \
//     if(doc.HasMember(#propertyName)){                               \
//         return doc[#propertyName].Get##repidAtomType();                      \
//       } else return 0;                                              \
//   }

using namespace rapidjson;
using namespace std;
class SnakeMetadata{
  public:
    
    SnakeMetadata(){
      doc.SetObject();
    };
    ~SnakeMetadata(){};

    const rapidjson::Value & DeSerialize(const std::string &str)
    {
      doc.Parse(str.c_str());
      return doc;
    }

    void Initialize(const std::string &str){
      DeSerialize(str);
    }
    
    const std::string Serialize()
    {
      StringBuffer buffer;
      Writer<StringBuffer> writer(buffer);
      doc.Accept(writer);
      return buffer.GetString();
    }
    
    template<typename T>
    T getValue(const char* propertyName)
    {
      if(doc.HasMember(propertyName)){
        T value = doc[propertyName].Get<T>();
        return value;
      } else return NULL;

    }
    template<typename T>
    T getValue(const std::string propertyName)
    {
      return getValue<T>(propertyName.c_str());
    }

    std::string getStringValue(const char* propertyName)
    { // FIXME(QJP) This is hard coding.
      if(doc[propertyName].IsBool())  return std::to_string(doc[propertyName].GetBool());
      if(doc[propertyName].IsInt())  return std::to_string(doc[propertyName].GetInt());
      if(doc[propertyName].IsUint())  return std::to_string(doc[propertyName].GetUint());
      if(doc[propertyName].IsInt64())  return std::to_string(doc[propertyName].GetInt64());
      if(doc[propertyName].IsUint64())  return std::to_string(doc[propertyName].GetUint64());
      if(doc[propertyName].IsDouble())  return std::to_string(doc[propertyName].GetDouble());
      if(doc[propertyName].IsString())  return doc[propertyName].GetString();
    }
    
    std::string getStringValue(std::string propertyName)
    {
      return getStringValue(propertyName.c_str());
    }

   void removeProperty(const char* propertyName)
    {
      if(doc.HasMember(propertyName)){
        doc.RemoveMember(propertyName);
      }
    }
    template<typename T>
    void addProperty(const char* propertyName, T propertyValue)
    {
      removeProperty(propertyName);
      rapidjson::Value v(propertyValue);
      doc.AddMember(rapidjson::StringRef(propertyName), 
        v, doc.GetAllocator());
    }
    void addStringProperty(const char* propertyName, const char* propertyValue)
    {
      removeProperty(propertyName);
      doc.AddMember(rapidjson::StringRef(propertyName),
        rapidjson::StringRef(propertyValue), doc.GetAllocator());
    }

  private:
    rapidjson::Document doc;
};
int main(int argc, char const *argv[])
{
  SnakeMetadata sm;
  const std::string str = "{\"int\":123, \"double\":234.01, \"float\":234.01, \"uint64_t\":123, \"const char*\":\"const char*\"}";
  sm.Initialize(str);
  
  //Test decimal
  cout<< sm.getValue<double>("double") << endl;
  cout<< sm.getValue<float>("float") << endl;
  
  //Test integers.
  cout<< sm.getValue<int>("int")<< endl;
  // sm.addProperty<uint16_t>("uint16_t", 16); //not supported
  sm.addProperty<uint32_t>("uint32_t", 32);
  sm.addProperty<uint64_t>("uint64_t", 64);
  // cout<< sm.getValue<uint16_t>("uint16_t") << endl;
  cout<< sm.getValue<uint32_t>("uint32_t") << endl;
  cout<< sm.getValue<uint64_t>("uint64_t") << endl;
  
  // sm.addProperty<int16_t>("int16_t", -16);
  sm.addProperty<int32_t>("int32_t", -32);
  sm.addProperty<int64_t>("int64_t", -64);
  // cout<< sm.getValue<int16_t>("int16_t") << endl;
  cout<< sm.getValue<int32_t>("int32_t") << endl;
  cout<< sm.getValue<int64_t>("int64_t") << endl;

  //Test string key.
  sm.addStringProperty("const char*", "const char* replaced");
  std::string key = "const char*";
  cout<< sm.getValue<const char*>("const char*") << endl;
  cout<< sm.getStringValue(key) << endl;

  return 0;
}

