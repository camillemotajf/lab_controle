import serial
import csv
import time

# Configurações da porta serial
serial_port = 'COM8'  # Defina a porta serial correta (exemplo para Linux)
baud_rate = 250000

# Abre a porta serial
ser = serial.Serial(serial_port, baud_rate)

# Abre o arquivo CSV para escrita
csv_file_path = 'dados_senoide_tensao.csv'
csv_file = open(csv_file_path, 'w', newline='')
csv_writer = csv.writer(csv_file)
csv_writer.writerow(['tempo', 'tensao'])

try:
    # Loop para ler continuamente os dados da porta serial
    first_line = True
    while True:
        # Lê uma linha da porta serial (deve ser uma linha de texto no formato "Velocidade: XXX RPM")
        line = ser.readline().decode('latin1').strip()
        print(line)

        if first_line:
            first_line = False
        # print("Primeira linha ignorada:", line)
            continue

        rpm_value, current_time = line.split(',')
        print("o trem la: ", rpm_value)
        rpm_value = float(rpm_value.split()[0])
        current_time = float(current_time.split()[0]) # Extrai apenas o valor numérico da velocidade RPM

        # Obtém o tempo atual em milissegundos
        # current_time = int(time.time() * 1000)
    
        # Escreve os dados no arquivo CSV
        csv_writer.writerow([current_time, rpm_value])


except KeyboardInterrupt:
    print("Interrompido pelo usuário.")

finally:
    # Fecha a porta serial e o arquivo CSV
    ser.close()
    csv_file.close()
