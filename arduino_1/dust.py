from influxdb_client import InfluxDBClient
import time
import serial

# InfluxDB 2.x 설정
influxdb_url = "http://localhost:8086"
influxdb_token = "tumKiRwVwZLiO1QR-qxoLSzmOuTsh3pn_PPf4qTxqB6sBdiKOdjJ9fK8cZ4SZCHSZfVmxPn0KMfC-t87sCArXg=="
influxdb_org = "test"
inlfuxdb_bucket = "dust"

# 시리얼 포트 설정
serial_port = "COM13"
baudrate = 9600
timeout = 2

# InfluxDB  클라이언트 
client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org)

# InfluxDB 클라이언트 설정 
write_api = client.write_api()

#시리얼 포트 열기
try:
    ser = serial.Serial(serial_port, baudrate, timeout = timeout)
    print(f"Connected to {serial_port} at {baudrate} baud")
except serial.SerialException:
    print("Failed to connect to serial port.")
    exit()
finally:
    ser.close()

#시리얼 데이터 읽기 및 influxDB 저장 
try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip() # 시리얼 데이터 읽기
            print(f"Received: {line}")
            if "=" in line:
                key, value = line.split("=")
                try:
                    value = float(value) # 숫자 변환
                    data = f"sensor_data,device=arduino {key}={value}"
                    write_api.write(bucket=influxdb_bucket, record=data)
                    print(f"Data written to InfluxDB: {key}={value}")

                except ValueError:
                    print("Invailed data format")

    time.sleep(1)#1초

except KeyboardInterrupt:
    print("Stopping data collection...")

finally:
    ser.close()
    
