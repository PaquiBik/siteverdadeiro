const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

const port = new SerialPort('/dev/tty.usbserial', { baudRate: 9600 });
const parser = port.pipe(new Readline({ delimiter: '\n' }));

port.on('open', () => {
  console.log('Conexão com o Arduino estabelecida.');
});

// Função para enviar um comando para o Arduino
function enviarComando(comando) {
  port.write(comando);
}

// Exemplo de como enviar um comando quando um botão é clicado
const botao1 = document.querySelector('#botao1');
botao1.addEventListener('click', () => {
  enviarComando('Comando para liberar 10ml de água');
});
