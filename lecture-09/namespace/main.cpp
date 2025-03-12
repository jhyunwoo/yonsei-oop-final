#include <iostream>
using std::cout;
using std::endl;

namespace YonseiNamespace { // namespace 선언
    void sayYonsei();
}

namespace YonseiNamespace { // namespace에서 함수 정의
    void sayYonsei(){
        cout << "Yonsei" << endl;
    }
}

using YonseiNamespace::sayYonsei; // YonseiNamespace에서 sayYonsei만 사용

namespace { // unnamed namespaces - 로컬에서만 사용, 다른 파일에서 사용 불가
 int count;
}

int main(){
  YonseiNamespace::sayYonsei(); // 함수 사용
    count = 5;
    cout << count << endl;
  return 0;
}
