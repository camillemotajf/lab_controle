import numpy as np
import matplotlib.pyplot as plt
import control as ctrl


num = [10.8]  # Numerador da FTMA
den = [0.1,1]  # Denominador da FTMA

# Criando a FTMA
G = ctrl.TransferFunction(num, den)

# Definindo os parâmetros do controlador PI
Kp = 3.0  # Ganho proporcional
Ki = 5.0  # Ganho integral

# Criando a função de transferência do controlador PI em s
C_s = ctrl.TransferFunction([Kp, Ki], [1, 0])

# Definindo o período de amostragem (por exemplo, 0.1 segundos)
Ts = 0.01

# Transformando o controlador de s para z usando a transformação Tustin
C_z = ctrl.c2d(C_s, Ts, method='tustin')

# Calculando a função de transferência de malha fechada (FTMF) em z com realimentação unitária
G_d = ctrl.c2d(G, Ts, method='tustin')
G_cl_z = ctrl.feedback(C_z * G_d, 1)

# Gerando a resposta ao degrau
t = np.arange(0, 10, Ts)  # Cria um vetor de tempo de 0 a 10 segundos com passo Ts
u = np.ones_like(t)  # Entrada de degrau unitário
t, y = ctrl.forced_response(G_cl_z, t, u)

# Plotando a resposta ao degrau
plt.figure()
plt.step(t, y, where='post')
plt.title('Resposta ao Degrau da FTMF Discreta com Controlador PI e Realimentação Unitária')
plt.xlabel('Tempo (s)')
plt.ylabel('Amplitude')
plt.grid(True)
plt.show()

# Exibindo a função de transferência discreta do controlador PI
print('Controlador PI em z:', C_z)
