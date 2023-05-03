import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton
from PyQt5.QtGui import QIcon


class MyWindow(QWidget):
    '''
    QWidget 클래스 상속을 통해 나만의 윈도우를 세팅함
    '''

    def __init__(self):
        # Inherit the constructor with 'super' keyword
        super().__init__()

        # 따로 메서드를 지정해서 시작 설정을 몰아넣는 게 국룰인듯?
        self.initUI()

    def initUI(self):
        # QIcon object를 통해 사용할 아이콘 사진 가져오기
        # 아이콘이 나타나지 않는 경우 -> 절대경로를 적으면 해결됨
        logo = QIcon('./assets/ALFSR_logo.png')
        simple_btn = QPushButton('Print', self)

        # 윈도우 제목 변경
        self.setWindowTitle('My Window Test')
        # 윈도우 생성좌표, 생성크기 설정 / 생성좌표는 모니터 좌상단부터!
        # self.setGeometry(0, 0, 1920, 1000)
        # 사이즈만 변경 (기본 생성은 화면 정중앙)
        self.resize(750, 400)
        # 윈도우 아이콘 변경
        self.setWindowIcon(logo)

        # simple_btn 설정
        simple_btn.resize(200, 30)
        # 얘는 윈도우랑 달리 위치 무조건 지정해줘야 함...
        simple_btn.move(275, 185)
        # JS의 eventListener처럼 눌렀을 때 실행이 되는 거라, 함수 뒤에 괄호 없이!
        simple_btn.clicked.connect(self.simple_btn_func)

    def simple_btn_func(self):
        # 꼭 클래스 안에 버튼 관련 메서드가 있어야 하는 것은 아니지만, 클래스 내의 버튼에 관한 것이니 되도록이면 안에 넣기!
        print('Peekaboo!')


app = QApplication(sys.argv)
window = MyWindow()
window.show()
app.exec_()
