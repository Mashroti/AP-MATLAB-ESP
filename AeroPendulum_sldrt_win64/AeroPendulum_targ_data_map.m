  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AeroPendulum_P)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% AeroPendulum_P.MAX
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AeroPendulum_P.MIN
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AeroPendulum_P.PIDController_InitialConditionForFilter
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AeroPendulum_P.PIDController_InitialConditionForIntegrator
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AeroPendulum_P.Ramp2_InitialOutput
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AeroPendulum_P.PacketOutput_MaxMissedTicks
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AeroPendulum_P.PacketOutput_MaxMissedTicks_k
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AeroPendulum_P.StreamInput_MaxMissedTicks
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AeroPendulum_P.PacketOutput_YieldWhenWaiting
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AeroPendulum_P.PacketOutput_YieldWhenWaiting_l
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 9;
	
	  ;% AeroPendulum_P.StreamInput_YieldWhenWaiting
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 10;
	
	  ;% AeroPendulum_P.Ramp2_slope
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 11;
	
	  ;% AeroPendulum_P.Ramp2_start
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AeroPendulum_P.PacketOutput_PacketID
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AeroPendulum_P.PacketOutput_PacketID_m
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% AeroPendulum_P.Constant1_Value
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AeroPendulum_P.Constant2_Value
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 2;
	
	  ;% AeroPendulum_P.Constant1_Value_h
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 4;
	
	  ;% AeroPendulum_P.Constant2_Value_m
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 6;
	
	  ;% AeroPendulum_P.Constant_Value
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 8;
	
	  ;% AeroPendulum_P.SineWave2_Amp
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 9;
	
	  ;% AeroPendulum_P.SineWave2_Bias
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 10;
	
	  ;% AeroPendulum_P.SineWave2_Freq
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 11;
	
	  ;% AeroPendulum_P.SineWave2_Phase
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 12;
	
	  ;% AeroPendulum_P.Step2_Time
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 13;
	
	  ;% AeroPendulum_P.Step2_Y0
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 14;
	
	  ;% AeroPendulum_P.Step2_YFinal
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 15;
	
	  ;% AeroPendulum_P.Step_Y0
	  section.data(13).logicalSrcIdx = 31;
	  section.data(13).dtTransOffset = 16;
	
	  ;% AeroPendulum_P.DiscreteFIRFilter1_InitialStates
	  section.data(14).logicalSrcIdx = 32;
	  section.data(14).dtTransOffset = 17;
	
	  ;% AeroPendulum_P.DiscreteFIRFilter1_Coefficients
	  section.data(15).logicalSrcIdx = 33;
	  section.data(15).dtTransOffset = 18;
	
	  ;% AeroPendulum_P.Gain_Gain
	  section.data(16).logicalSrcIdx = 34;
	  section.data(16).dtTransOffset = 20;
	
	  ;% AeroPendulum_P.Pgain_Value
	  section.data(17).logicalSrcIdx = 35;
	  section.data(17).dtTransOffset = 21;
	
	  ;% AeroPendulum_P.Dgain_Value
	  section.data(18).logicalSrcIdx = 36;
	  section.data(18).dtTransOffset = 22;
	
	  ;% AeroPendulum_P.N_Value
	  section.data(19).logicalSrcIdx = 37;
	  section.data(19).dtTransOffset = 23;
	
	  ;% AeroPendulum_P.OFF_Gain
	  section.data(20).logicalSrcIdx = 38;
	  section.data(20).dtTransOffset = 24;
	
	  ;% AeroPendulum_P.Igain_Value
	  section.data(21).logicalSrcIdx = 39;
	  section.data(21).dtTransOffset = 25;
	
	  ;% AeroPendulum_P.Memory_InitialCondition
	  section.data(22).logicalSrcIdx = 40;
	  section.data(22).dtTransOffset = 26;
	
	  ;% AeroPendulum_P.Gain1_Gain
	  section.data(23).logicalSrcIdx = 41;
	  section.data(23).dtTransOffset = 27;
	
	  ;% AeroPendulum_P.Stopsim_Value
	  section.data(24).logicalSrcIdx = 42;
	  section.data(24).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AeroPendulum_B)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% AeroPendulum_B.Step2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AeroPendulum_B.IndexVector
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AeroPendulum_B.StreamInput
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AeroPendulum_B.Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AeroPendulum_B.Sum1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AeroPendulum_B.NProdOut
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AeroPendulum_B.OFF
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AeroPendulum_B.Gain1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AeroPendulum_B.IProdOut
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AeroPendulum_B.y
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AeroPendulum_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AeroPendulum_DW.DiscreteFIRFilter1_states
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AeroPendulum_DW.Memory_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% AeroPendulum_DW.StreamInput_PWORK
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AeroPendulum_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 2;
	
	  ;% AeroPendulum_DW.PacketOutput_PWORK
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 4;
	
	  ;% AeroPendulum_DW.PacketOutput_PWORK_i
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AeroPendulum_DW.DiscreteFIRFilter1_circBuf
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AeroPendulum_DW.EnabledSubsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AeroPendulum_DW.EnabledSubsystem_SubsysRanBC
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3759554766;
  targMap.checksum1 = 883985094;
  targMap.checksum2 = 1094181789;
  targMap.checksum3 = 3668168831;

