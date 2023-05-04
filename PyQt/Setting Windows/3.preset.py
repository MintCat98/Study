import sys
import typing
from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton
from PyQt5.QtGui import QIcon


class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
    '''
    PyQt5가 제공하는 윈도우os용 전용 클래스
    아래의 틀이 갖춰져 있음
    - Menu Bar
    - Toolbars
        |-Dock Widgets
            |- Central Widgets
    - Status Bar
    '''


app = QApplication(sys.argv)
window = MyWindow()
window.show()
app.exec_()
