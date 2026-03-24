project('fjordwl', ['c', 'cpp'],
  version : '0.0.1',
)

subdir('protocols')

is_nixos = false
os_release = run_command('cat', '/etc/os-release', check: false)
if os_release.returncode() == 0
    if os_release.stdout().contains('ID=nixos')
        is_nixos = true
    endif
endif

prefix = get_option('prefix')
sysconfdir = get_option('sysconfdir')

if sysconfdir.startswith(prefix) and not is_nixos
  sysconfdir = sysconfdir.substring(prefix.length())
  if not sysconfdir.startswith('/')
    sysconfdir = '/' + sysconfdir
  endif
endif

cc = meson.get_compiler('c')
libm = cc.find_library('m')
xcb = dependency('xcb', required : get_option('xwayland'))
xlibs = dependency('xcb-icccm', required : get_option('xwayland'))
wayland_server_dep = dependency('wayland-server',version: '>=1.23.1')
wlroots_dep = dependency('wlroots-0.19',version: '>=0.19.0')
xkbcommon_dep = dependency('xkbcommon')
libinput_dep = dependency('libinput',version: '>=1.27.1')
libwayland_client_dep = dependency('wayland-client')
pcre2_dep = dependency('libpcre2-8')
libscenefx_dep = dependency('scenefx-0.4',version: '>=0.4.1')


git = find_program('git', required : false)
is_git_repo = false

if git.found()
  git_status = run_command(git, 'rev-parse', '--is-inside-work-tree', check : false)
  if git_status.returncode() == 0 and git_status.stdout().strip() == 'true'
    is_git_repo = true
  endif
endif

if is_git_repo
  commit_hash = run_command(git, 'rev-parse', '--short', 'HEAD', check : false).stdout().strip()
  latest_tag = meson.project_version()
  version_with_hash = '@0@(@1@)'.format(latest_tag, commit_hash)
else
  commit_hash = 'release'
  latest_tag = meson.project_version()
  version_with_hash = '@0@(@1@)'.format(latest_tag, commit_hash)
endif

c_args = [
  '-g',
  '-Wno-unused-function',
  '-DWLR_USE_UNSTABLE',
  '-D_POSIX_C_SOURCE=200809L',
  '-DVERSION="@0@"'.format(version_with_hash),
  '-DSYSCONFDIR="@0@"'.format('/etc'),
]

if get_option('asan')
  c_args += [
    '-fsanitize=address',
    '-fno-omit-frame-pointer',
    '-fno-optimize-sibling-calls'
  ]
endif

if xcb.found() and xlibs.found()
  c_args += '-DXWAYLAND'
endif

link_args = []
if get_option('asan')
  link_args += '-fsanitize=address'
endif

executable('fjordwl',
  'src/fjordwl.c',
  'src/common/util.c',
  'src/ext-protocol/wlr_ext_workspace_v1.c',
  wayland_sources,
  include_directories : include_directories('.'),
  dependencies : [
    libm,
    xcb,
    xlibs,
    libscenefx_dep,
    wayland_server_dep,
    wlroots_dep,
    xkbcommon_dep,
    libinput_dep,
    libwayland_client_dep,
    pcre2_dep,
  ],
  install : true,
  c_args : c_args,
  link_args : link_args,
)

# build mmsg
dwl_ipc_protocol = 'protocols/dwl-ipc-unstable-v2.xml'

wayland_scanner_client_header = generator(
  wayland_scanner,
  output: '@BASENAME@-protocol.h', 
  arguments: ['client-header', '@INPUT@', '@OUTPUT@']
)

wayland_scanner_private_code = generator(
  wayland_scanner,
  output: '@BASENAME@-protocol.c',
  arguments: ['private-code', '@INPUT@', '@OUTPUT@']
)

executable('mmsg',
  'mmsg/mmsg.c',
  wayland_scanner_private_code.process(dwl_ipc_protocol),
  wayland_scanner_client_header.process(dwl_ipc_protocol),
  dependencies: [
    libwayland_client_dep
  ],
  install: true,
  c_args: [
    '-g',
    '-Wno-unused-function',
  ],
)

desktop_install_dir = join_paths(prefix, 'share/wayland-sessions')
portal_install_dir = join_paths(prefix, 'share/xdg-desktop-portal')
install_data('assets/fjordwl.desktop', install_dir : desktop_install_dir)
install_data('assets/fjordwl-portals.conf', install_dir : portal_install_dir)
