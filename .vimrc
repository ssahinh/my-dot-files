" my vim configurations
autocmd filetype cpp nnoremap <F5> :w <bar> !g++-4.8 -ulimit -Wall -Wno-unused-result -std=c++11   -O2   % -o %:r && ./%:r <CR>
syntax on
set nu
set clipboard=unnamedplus
set mouse=a
set tabstop=2
set autoindent
set shiftwidth=2
set softtabstop=2
set smarttab
set expandtab
set smartcase
filetype indent on

set t_Co=256
set background=dark
colorscheme solarized 

autocmd filetype java nnoremap <F5> :w <bar> !javac % && java -enableassertions %:r <CR>
autocmd filetype python nnoremap <F5> :w <bar> !python % <CR>
autocmd filetype perl nnoremap <F5> :w <bar> !perl % <CR>
autocmd filetype go nnoremap <F5> :w <bar> !go build % && ./%:r <CR>
"my settings end

" vim plug configuration
" Specify a directory for plugins
" - For Neovim: ~/.local/share/nvim/plugged
" - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.vim/plugged')

" Make sure you use single quotes

" Shorthand notation; fetches https://github.com/junegunn/vim-easy-align
Plug 'junegunn/vim-easy-align'

" Any valid git URL is allowed
Plug 'https://github.com/junegunn/vim-github-dashboard.git'

" Multiple Plug commands can be written in a single line using | separators
Plug 'SirVer/ultisnips' | Plug 'honza/vim-snippets'

" On-demand loading
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'tpope/vim-fireplace', { 'for': 'clojure' }
" Give a shortcut key to NERD Tree
map <F2> :NERDTreeToggle<CR>
map <F3> :Minimap<CR>
"autocmd VimEnter * NERDTree
autocmd VimEnter * wincmd p
" Using a non-master branch
Plug 'rdnetto/YCM-Generator', { 'branch': 'stable' }

" Using a tagged release; wildcard allowed (requires git 1.9.2 or above)
Plug 'fatih/vim-go', { 'tag': '*' }
Plug 'scrooloose/syntastic'
Plug 'kien/ctrlp.vim'
Plug 'bling/vim-airline'
Plug 'jistr/vim-nerdtree-tabs'
Plug 'pangloss/vim-javascript'
Plug 'elzr/vim-json'
Plug 'klen/python-mode'
Plug 'ervandew/supertab'
Plug 'rip-rip/clang_complete'
Plug 'dracula/vim'
Plug 'altercation/vim-colors-solarized'
Plug 'severin-lemaignan/vim-minimap'
Plug 'shawncplus/phpcomplete.vim'
" let g:nerdtree_tabs_open_on_console_startup=1

" Plugin options
Plug 'nsf/gocode', { 'tag': 'v.20150303', 'rtp': 'vim' }

" Plugin outside ~/.vim/plugged with post-update hook
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }

" Unmanaged plugin (manually installed and updated)
Plug '~/my-prototype-plugin'

" Initialize plugin system
call plug#end()
