" path to .vimprj folder
let s:sVimprjPath = expand('<sfile>:p:h')

" change current working directory to root of .vimprj
execute 'cd '.s:sVimprjPath.'/..'

" map Ctrl-F5 to update tags
nnoremap <C-F5> :silent !ctags -R --exclude=build --languages=c++<cr>

" auto make seesion when leave
autocmd VimLeave * execute 'mksession! '.s:sVimprjPath.'/prj.session'
