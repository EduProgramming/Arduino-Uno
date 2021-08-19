import sys, time
import serial
import serial.tools.list_ports
from PyQt5 import uic
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

form_class = uic.loadUiType("./main.ui")[0]
ports = list(serial.tools.list_ports.comports())
ser = None

is_arduino_list = ['USB-SERIAL CH340', 'USB Serial Port', 'USB Serial']

class MyApp(QMainWindow, form_class):
    def __init__(self):
        super(MyApp, self).__init__()
        self.setupUi(self)
        
        for port in ports:
            for is_arduino in is_arduino_list:
                if is_arduino in str(port):
                    self.comboBox.addItem(str(port.device))
        
        self.connectingButton.clicked.connect(self.arduinoConnect)
        self.buttonA.clicked.connect(self.sendData('a'))
        self.buttonB.clicked.connect(self.sendData('b'))
        self.buttonC.clicked.connect(self.sendData('c'))
        self.sendButton.clicked.connect(self.sendButtonData)

    def arduinoConnect(self):
        global ser
        portNum = self.comboBox.currentText()
        if self.connectingButton.text() == '연결':
            ser = serial.Serial(f'{portNum}', 9600)
            time.sleep(3)
            self.buttonA.setEnabled(True)
            self.buttonB.setEnabled(True)
            self.buttonC.setEnabled(True)
            self.sendButton.setEnabled(True)
            self.connectingButton.setText('끊기')
        elif self.connectingButton.text() == '끊기':
            self.buttonA.setDisabled(False)
            self.buttonB.setDisabled(False)
            self.buttonC.setDisabled(False)
            self.sendButton.setDisabled(False)
            ser.close()
            ser = None
            self.connectingButton.setText('연결')

    def sendData(self, data):
        def getData():
            ser.write(data.encode())
        return getData

    def sendButtonData(self):
        data = self.lineEdit.text()
        ser.write(data.encode())


if __name__ == '__main__':
   app = QApplication(sys.argv)
   ex = MyApp()
   ex.show()
   app.exec_()