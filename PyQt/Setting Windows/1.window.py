import sys
from PyQt5.QtWidgets import QApplication, QWidget

app = QApplication(sys.argv)        # QApplication object 생성
                                    # sys.argv: 현 실행 파일의 절대 경로를 담고 있는 리스트

window = QWidget()                  # QWidget object 생성 => 윈도우를 메모리에 할당
window.show()                       # 메모리에 할당된 윈도우를 화면에 출력
'''
내부적으로 while 무한 루프 포함!
    if [윈도우 종료 버튼] -> break
'''
app.exec_()                         # event 시작