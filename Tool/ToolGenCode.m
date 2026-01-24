function ToolGenCode()

    Model = 'ASW';
    
    if(~bdIsLoaded(Model))
        load_system(Model);
    end
    
    slbuild(Model);
    coder.report.generate(Model);

    close_system(Model);

    % copyHBridgeFiles();

end

