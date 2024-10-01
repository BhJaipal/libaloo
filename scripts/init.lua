package.path = "share/lua/5.1/?.lua;share/lua/5.1/?/?.lua"
local ltui = require("ltui")
local application = ltui.application
local event = ltui.event
local rect = ltui.rect
local window = ltui.window
local tui = application()

largeLogo = [[
\n ██████╗   ██╗         █████╗        █████╗
\n██╔═══██║  ██║       ██╔════██╗    ██╔════██╗
\n████████║  ██║      ██║      ██║  ██║      ██║
\n██║   ██║  ██║       ██╚════██╝    ██╚════██╝
\n██║   ██╝  ██████║     █████╝        █████╝
]]
function tui:init()
	application.init(self, "demo")
	self:background_set("blue")
	self:insert(window:new("window.main", rect({ 1, 1, self:width() - 1, self:height() - 1 }), largeLogo, true))
	-- self:insert(window:new("window.main", rect({ 1, 1, self:width() - 1, self:height() - 1 }), "main window", true))
end
tui:run()
