function varargout = AeroPendulum_GUI(varargin)
% AEROPENDULUM_GUI MATLAB code for AeroPendulum_GUI.fig
%      AEROPENDULUM_GUI, by itself, creates a new AEROPENDULUM_GUI or raises the existing
%      singleton*.
%
%      H = AEROPENDULUM_GUI returns the handle to a new AEROPENDULUM_GUI or the handle to
%      the existing singleton*.
%
%      AEROPENDULUM_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in AEROPENDULUM_GUI.M with the given input arguments.
%
%      AEROPENDULUM_GUI('Property','Value',...) creates a new AEROPENDULUM_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before AeroPendulum_GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to AeroPendulum_GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help AeroPendulum_GUI

% Last Modified by GUIDE v2.5 26-May-2020 22:50:13

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @AeroPendulum_GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @AeroPendulum_GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before AeroPendulum_GUI is made visible.
function AeroPendulum_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to AeroPendulum_GUI (see VARARGIN)

% Choose default command line output for AeroPendulum_GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes AeroPendulum_GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);
instrreset
clc

folder = matlab.desktop.editor.getActiveFilename;
z = split(folder,"\");
[x y] = size(z);
folder = erase(folder,z(x,y));
cd (folder)

a = what;
handles.sys_name = erase(string(a.slx),'.slx');

guidata(hObject, handles);
load_system(handles.sys_name);
open_system(handles.sys_name);
set_param(handles.sys_name+'/OFF','Gain','0');
set_param(handles.sys_name+'/OFF1','Gain','0');
set_param(handles.sys_name+'/Manual Switch','sw','0');
set_param(handles.sys_name+'/MySystem/Stop sim','Value','0');
save_system(handles.sys_name);


set(handles.ampiltude,'string',get_param(handles.sys_name+'/Sine Wave','Amplitude'));
set(handles.bias,'string',get_param(handles.sys_name+'/Sine Wave','Bias'));
set(handles.setpoint,'string',get_param(handles.sys_name+'/SetPoint','Value'));

set(handles.pgain,'string',get_param(handles.sys_name+'/PID Controller','P'));
set(handles.igain,'string',get_param(handles.sys_name+'/PID Controller','I'));
set(handles.dgain,'string',get_param(handles.sys_name+'/PID Controller','D'));
set(handles.ngain,'string',get_param(handles.sys_name+'/PID Controller','N'));

list = instrhwinfo('serial');
set(handles.ComPort,'string',list.SerialPorts);

movegui('northwest');

% --- Outputs from this function are returned to the command line.
function varargout = AeroPendulum_GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


function setpoint_Callback(hObject, eventdata, handles)
% hObject    handle to setpoint (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of setpoint as text
%        str2double(get(hObject,'String')) returns contents of setpoint as a double


% --- Executes during object creation, after setting all properties.
function setpoint_CreateFcn(hObject, eventdata, handles)
% hObject    handle to setpoint (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function gain_Callback(hObject, eventdata, handles)
% hObject    handle to gain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of gain as text
%        str2double(get(hObject,'String')) returns contents of gain as a double


% --- Executes during object creation, after setting all properties.
function gain_CreateFcn(hObject, eventdata, handles)
% hObject    handle to gain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in ComPort.
function ComPort_Callback(hObject, eventdata, handles)
% hObject    handle to ComPort (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns ComPort contents as cell array
%        contents{get(hObject,'Value')} returns selected item from ComPort

% save_system(handles.sys_name);


% --- Executes during object creation, after setting all properties.
function ComPort_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ComPort (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
list = instrhwinfo('serial')
set(handles.ComPort,'string',list.SerialPorts)


function pgain_Callback(hObject, eventdata, handles)
% hObject    handle to pgain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of pgain as text
%        str2double(get(hObject,'String')) returns contents of pgain as a double


% --- Executes during object creation, after setting all properties.
function pgain_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pgain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function igain_Callback(hObject, eventdata, handles)
% hObject    handle to igain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of igain as text
%        str2double(get(hObject,'String')) returns contents of igain as a double


% --- Executes during object creation, after setting all properties.
function igain_CreateFcn(hObject, eventdata, handles)
% hObject    handle to igain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function dgain_Callback(hObject, eventdata, handles)
% hObject    handle to dgain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of dgain as text
%        str2double(get(hObject,'String')) returns contents of dgain as a double


% --- Executes during object creation, after setting all properties.
function dgain_CreateFcn(hObject, eventdata, handles)
% hObject    handle to dgain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

Pg = get(handles.pgain,'String');
if Pg ==""
    Pg = '0';
    set(handles.pgain,'String','0');
end
set_param(handles.sys_name+'/PID Controller','P',Pg);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ig = get(handles.igain,'String');
if Ig ==""
    Ig = '0';
    set(handles.igain,'String','0');
end
set_param(handles.sys_name+'/PID Controller','I',Ig);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Dg = get(handles.dgain,'String');
if Dg ==""
    Dg = '0';
    set(handles.dgain,'String','0');
end
set_param(handles.sys_name+'/PID Controller','D',Dg);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ng = get(handles.ngain,'String');
if Ng ==""
    Ng = '0';
    set(handles.ngain,'String','0');
end
set_param(handles.sys_name+'/PID Controller','N',Ng);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Sp = get(handles.setpoint,'String');
if Sp ==""
    Sp = '0';
    set(handles.setpoint,'String','0');
end
set_param(handles.sys_name+'/SetPoint','Value',Sp);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
amplitude = get(handles.ampiltude,'String');
if amplitude ==""
    amplitude = '0';
    set(handles.amplitude,'String','0');
end
set_param(handles.sys_name+'/Sine Wave','Amplitude',amplitude);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bias = get(handles.bias,'String');
if bias ==""
    bias = '0';
    set(handles.bias,'String','0');
end
set_param(handles.sys_name+'/Sine Wave','Bias',bias);
% save_system(handles.sys_name);


% --- Executes on button press in OnOff.
function OnOff_Callback(hObject, eventdata, handles)
% hObject    handle to OnOff (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of OnOff
x = get(hObject,'Value');
if x == 1
    set(hObject,'String','Motor ON');
    set_param(handles.sys_name+'/OFF','Gain','1');
    set_param(handles.sys_name+'/OFF1','Gain','1');
else 
        set(hObject,'String','Motor OFF');
    set_param(handles.sys_name+'/OFF','Gain','0');
    set_param(handles.sys_name+'/OFF1','Gain','0');
end
% save_system(handles.sys_name);


% --- Executes on button press in togglebutton3.
function togglebutton3_Callback(hObject, eventdata, handles)
% hObject    handle to togglebutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of togglebutton3


% --- Executes when selected object is changed in setpointtype.
function setpointtype_SelectionChangedFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in setpointtype 
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
blah = get(handles.setpointtype,'SelectedObject');
setpointString = get(blah,'string');

switch setpointString
    case 'Step'
        set_param(handles.sys_name+'/Manual Switch','sw','0');
        
    case 'Sine wave'
        set_param(handles.sys_name+'/Manual Switch','sw','1');
        
end



function ampiltude_Callback(hObject, eventdata, handles)
% hObject    handle to ampiltude (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of ampiltude as text
%        str2double(get(hObject,'String')) returns contents of ampiltude as a double


% --- Executes during object creation, after setting all properties.
function ampiltude_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ampiltude (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function bias_Callback(hObject, eventdata, handles)
% hObject    handle to bias (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of bias as text
%        str2double(get(hObject,'String')) returns contents of bias as a double


% --- Executes during object creation, after setting all properties.
function bias_CreateFcn(hObject, eventdata, handles)
% hObject    handle to bias (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes on button press in runsim.
function runsim_Callback(hObject, eventdata, handles)
% hObject    handle to runsim (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param(handles.sys_name+'/MySystem/Stop sim','Value','0');
% sim(handles.sys_name);
set_param(handles.sys_name, 'SimulationCommand', 'start');

% --- Executes on button press in stopsim.
function stopsim_Callback(hObject, eventdata, handles)
% hObject    handle to stopsim (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param(handles.sys_name+'/MySystem/Stop sim','Value','1');
t = timer;
t.StartDelay = 1;
t.TimerFcn = @(myTimerObj, thisEvent)timer_func(t, handles);
start(t)


function timer_func(t,handles)
set_param(handles.sys_name+'/MySystem/Stop sim','Value','0');
stop(t);
delete(t);


% --- Executes on button press in SetComPort.
function SetComPort_Callback(hObject, eventdata, handles)
% hObject    handle to SetComPort (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

x = get(handles.ComPort,'string');
Port = string(x(get(handles.ComPort,'Value')));
Port = erase(Port,"COM");

set_param(handles.sys_name+'/MySystem/Stream Input','DrvName','Standard_Devices/Serial_Port');
set_param(handles.sys_name+'/MySystem/Stream Input','DrvAddress',Port);
set_param(handles.sys_name+'/MySystem/Stream Input','DrvOptions','[115200 8 0 0 0 0 0 0]');

set_param(handles.sys_name+'/MySystem/Enabled Subsystem/Packet Output','DrvName','Standard_Devices/Serial_Port');
set_param(handles.sys_name+'/MySystem/Enabled Subsystem/Packet Output','DrvAddress',Port);
set_param(handles.sys_name+'/MySystem/Enabled Subsystem/Packet Output','DrvOptions','[115200 8 0 0 0 0 0 0]');

set_param(handles.sys_name+'/MySystem/Enabled Subsystem2/Packet Output','DrvName','Standard_Devices/Serial_Port');
set_param(handles.sys_name+'/MySystem/Enabled Subsystem2/Packet Output','DrvAddress',Port);
set_param(handles.sys_name+'/MySystem/Enabled Subsystem2/Packet Output','DrvOptions','[115200 8 0 0 0 0 0 0]');

% set_param(handles.sys_name+'/MySystem/Serial Configuration','ComPortMenu',Port);
% set_param(handles.sys_name+'/MySystem/Serial Configuration','ComPort',Port);
% set_param(handles.sys_name+'/MySystem/Serial Configuration','ObjConstructor','serial('''+Port+''');');
% 
% set_param(handles.sys_name+'/MySystem/Serial Receive','ComPortMenu',Port);
% set_param(handles.sys_name+'/MySystem/Serial Receive','ComPort',Port);
% 
% set_param(handles.sys_name+'/MySystem/Serial Send','ComPortMenu',Port);
% set_param(handles.sys_name+'/MySystem/Serial Send','ComPort',Port);

save_system(handles.sys_name);


% --- Executes during object creation, after setting all properties.
function figure1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called



function ngain_Callback(hObject, eventdata, handles)
% hObject    handle to ngain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of ngain as text
%        str2double(get(hObject,'String')) returns contents of ngain as a double


% --- Executes during object creation, after setting all properties.
function ngain_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ngain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Enable_track.
function Enable_track_Callback(hObject, eventdata, handles)
% hObject    handle to Enable_track (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Enable_track


% --- Executes on slider movement.
function slider1_Callback(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
