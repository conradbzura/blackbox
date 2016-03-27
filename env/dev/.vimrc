set exrc
set secure

syntax enable

set tabstop=4 " number of virtual spaces per tab
set softtabstop=4 " number of spaces per tab when editing
set expandtab " tabs are spaces
set number " show line numbers
set showcmd " show last command in bottom bar
set cursorline " highlight current line
filetype indent on " load filetype-specific indent files
set wildmenu " visual autocomplete for command menu
set lazyredraw " redraw only when necessary
set showmatch " highlight matchings braces/brackets/parentheses
set incsearch " search as characters are entered
set hlsearch " highlight matches
" turn off search highlight with ',<space>'
nnoremap <leader><space> :nohlsearch<CR>
set foldenable " enable folding
set foldlevelstart=10 " open most folds by default
set foldnestmax=10 " set maximum number of nested folds
" 'z' opens/closes folds
nnoremap <z> za
set foldmethod=syntax " fold based on syntax

set t_Co=256

colorscheme molokai
colorscheme gruvbox



let mapleader=","






" Vundle config

set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" YouCompleteMe
Plugin 'Valloric/YouCompleteMe'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
