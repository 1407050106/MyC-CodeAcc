#include <iostream>
#include "test.h"

//using namespace sockets;

off_t fileSize;
std::stringstream content;
std::string kBoundary = "----WebKitFormBoundaryKPjN0GYtWEjAni5F";
std::string contentEnd = "\r\n--" + kBoundary + "--\r\n";

int main()
{

	HttpRequest ImageReq("http://img.zcool.cn/community/01ddc256eb71586ac7257d209712b7.jpg@1280w_1l_2o_100sh.jpg");
	ImageReq.setRequestMethod("GET");
	ImageReq.setRequestProperty("Cache-Control", "no-cache");
	ImageReq.setRequestProperty("Content-Type", "application/octet-stream");
	ImageReq.setRequestProperty("Connection", "close\r\n");

	ImageReq.connect();
	ImageReq.send();
	ImageReq.handleRead();
	ImageReq.downloadFile("./test.jpg");

	//UPLOAD
	//off_t fileSize = FileSize(uploadFile);
	fileSize = sizeof(fopen("home/fanuc/cjson.json", "rb"));
	LOG_DEBUG << "fileSize : " << fileSize;
	
	content << "--" + kBoundary << "\r\n";
	content << "Content-Disposition: form-data; name=\"upload\"; filename=\"testjson.file\"\r\n";
	content << "Content-Type: text/plain\r\n\r\n";

	HttpRequest upload("http://img.zcool.cn/community/01ddc256eb71586ac7257d209712b7.jpg");
	upload.setRequestMethod("POST");
	upload.setRequestProperty("Content-Type", "multipart/form-data; boundary=" + kBoundary);
	upload.setRequestProperty("Cache-Control", "no-cache");
	upload.setRequestProperty("Content-Length", std::to_string(fileSize + content.str().size() + contentEnd.size()));
	upload.setRequestProperty("Connection", "close\r\n");
	upload.setRequestBody(content.str());

	ImageReq.uploadFile("home/fanuc/cjosn.json",contentEnd);

	return 0;
}


