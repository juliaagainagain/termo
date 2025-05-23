# Termo em C

Uma versão em C do famoso jogo [**Termo**](https://term.ooo), jogável diretamente no terminal.  
O objetivo é simples: adivinhar a palavra secreta de 5 letras em até 6 tentativas.


## 🕹️ Como jogar

A cada tentativa, o jogo te dá dicas sobre as letras:

| Símbolo | Significado                         |
|--------|-------------------------------------|
| `[ V ]` | Letra correta na posição correta     |
| `[ - ]` | Letra existe, mas está na posição errada |
| `[   ]` | Letra não aparece na palavra        |

### Compilar e rodar:
```bash
gcc termo.c -o termo


./termo           # Linux/macOS
termo.exe         # Windows

