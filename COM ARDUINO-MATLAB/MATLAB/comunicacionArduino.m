clear all
close all
clc
format short

% Para MATLAB 2025, se recomienda usar serialport en lugar de serial (legacy)
canal_serie = serialport('COM4', 9600);
configureTerminator(canal_serie, "CR/LF");

figure;
xlabel('Segundos');
ylabel('Datos');
title('Adquisición de datos Arduino');
grid on;
hold on;

prop = animatedline('Color', 'b', 'LineWidth', 1);

% Limpiar buffer inicial
flush(canal_serie);
clc;

disp('Adquisición de datos de la tarjeta Arduino UNO: utilizar el sketch cap8_funciones');

i = 1;
while i < 1000
    % Leer datos del puerto serial
    datos_str = readline(canal_serie);
    datos = sscanf(datos_str, '%f %f');
    
    if length(datos) == 2
        y = datos(1);
        x = datos(2);
        addpoints(prop, x, y);
        drawnow;
        i = i + 1;
    end
end

% Limpiar y cerrar puerto
clear canal_serie;