#include "main.h"
#include "util.h"

#include <fstream>
#include <sstream>

//#include <chrono>
//#include <thread>

#include <stddef.h>
#include <stdint.h>

uint32_t crc32(const unsigned char *s,size_t n) {
	uint32_t crc=0xFFFFFFFF;
	
	for(size_t i=0;i<n;i++) {
		char ch=s[i];
		for(size_t j=0;j<8;j++) {
			uint32_t b=(ch^crc)&1;
			crc>>=1;
			if(b) crc=crc^0xEDB88320; //0x04C11DB7
			ch>>=1;
		}
	}
	
	return ~crc;
}

std::string ideCAD::checksum(std::u16string filename)
{
  std::ifstream file(convert2String(std::wstring(filename.begin(), filename.end())).c_str(), std::ios::binary);
  file.seekg(0, std::ios::end);
  std::streampos size = file.tellg();
  file.seekg(0, std::ios::beg);
  std::vector<unsigned char> buffer;
  buffer.resize(size);
  file.read((char *) buffer.data(), buffer.size());

  uint32_t crc = crc32(buffer.data(), buffer.size());
  std::stringstream ss;
  ss << std::hex << crc;

  return ss.str();
}

Napi::String ideCAD::checksumWrapped(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  // check if arguments are integer only.
  if (info.Length() < 1 || !info[0].IsString())
  {
    Napi::TypeError::New(env, "arg1::String expected").ThrowAsJavaScriptException();
  }
  // convert javascripts datatype to c++
  Napi::String filename = info[0].As<Napi::String>();
  // run c++ function return value and return it in javascript
  Napi::String returnValue = Napi::String::New(env, ideCAD::checksum(filename.Utf16Value()));

  return returnValue;
}

Napi::Object ideCAD::Init(Napi::Env env, Napi::Object exports)
{
  // export Napi function
  exports.Set("file_checksum", Napi::Function::New(env, ideCAD::checksumWrapped));
  return exports;
}