nnoremap <F1> :Make<cr>
nnoremap <F3> :Termdebug ./build/debug/morpheus<cr>
nnoremap <F4> :ter ++close ./build/debug/morpheus .<cr>

packadd termdebug
let g:termdebug_wide = 1

let g:syntastic_cpp_compiler_options = '-DDEBUG -std=c++17'
let g:syntastic_cpp_include_dirs = [ 'build/debug', 'ECS/src', 'box2d/Box2D', '/usr/include/SDL2' ]
