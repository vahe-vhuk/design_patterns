#include <iostream>
#include <string>

class FileDownloader 
{
public:
    virtual void download(const std::string& fileUrl) = 0;
};

class RealFileDownloader : public FileDownloader 
{
public:
    void download(const std::string& fileUrl) override {
        std::cout << "Downloading file from: " << fileUrl << '\n';
        std::cout << "File downloaded successfully!\n";
    }
};

class FileDownloaderProxy : public FileDownloader 
{
private:
    FileDownloader* realDownloader;

public:
    FileDownloaderProxy() 
		:	realDownloader(nullptr) 
	{}

    void download(const std::string& fileUrl) override {
        if (realDownloader == nullptr) {
            realDownloader = new RealFileDownloader();
        }
        std::cout << "Proxy: Before downloading...\n";
        realDownloader->download(fileUrl);
        std::cout << "Proxy: After downloading...\n";
    }
};

int main() {
    FileDownloaderProxy downloaderProxy;

    downloaderProxy.download("file.txt");

    return 0;
}

