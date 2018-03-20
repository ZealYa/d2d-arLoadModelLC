function y = chainDetection(model, parameter, range, numOfLHS, chainID)
%Estimates the length of a linear chain specified in the model file based on
%parameter identifiability
%
%chainDetection(range, chainID, numOfLHS)
%
%range [1:5]        range of chain lengths to try                   
%chainID [1]        numeric identifier in case of multiple chains
%numOfLHS [10]      number of LHS runs for fitting                  

    if ~exists(range, 'var')
        range = 1:5;
    end
    
    if ~exists(chainID, 'var')
        chainID = 1;
    end
    
    if ~exists(numOfLHS, 'var')
        numOfLHS = 10;
    end
    
    global ar
    delay_par_nidty = NaN(size(range, 2), 1);
    exit_par_nidty = NaN(size(range, 2), 1);
    chi2list = NaN(size(range, 2), size(ar.p, 2));
    
    for i = range
        arInit;
        ar.chain.lengths(chainID) = i;
        arLoadModel(model)
        arFit;
        arFitLHS(numOfLHS);
        arSave(sprintf('chDet_cl_%02d', i));
        
        arPLEInit;
        %ple([]) only delay and deg parameters -> in arLoadModel im ar
        %struct speichern ar.chain.chainpar ar.chain.exitpar
        delay_par = find(strcmp(ar.pLabel, 'k_del'));
        exit_par = find(strcmp(ar.pLabel, 'parameter'));
        ple([delay_par, exit_par]);
        
        arSave(sprintf('chDet_cl_%02d', i));
        
        if ar.ple.conf_ub_point(delay_par) == Inf && ...
                ar.ple.conf_ub_point(delay_par) > 0.99 * ar.ub(delay_par) 
            delay_par_nidty(i) = 1;
        else
            delay_par_nidty(i) = 0;
        end
        
        if ar.ple.conf_ub_point(exit_par) == Inf && ...
                ar.ple.conf_ub_point(exit_par) > 0.99 * ar.ub(exit_par)
            exit_par_nidty(i) = 1;
        else
            exit_par_nidty(i) = 0;
        end
        
        chi2list(i) = ar.p;
        
    end
   
    T = table(range, chi2list, delay_par_nidty, exit_par_nidty);
    T.Properties.VariableNames = {'Chain Length', 'Chi2 value',...
        sprintf('%s identifable?', ar.pLabel(delay_par)), ...
        sprintf('%s identifable?'), ar.pLabel(exit_par)};
    
    if exit_par_nidty == ones(size(range, 2), 1)
        estimatedCL = 0
        sprintf('Delay parameter not identifable. Optimal chain length zero.')
    else
        for i = range
            if delay_par_nidty(i) == 1
                estimatedCL = i - 1
            end
        end
        sprintf('Optimal chain length %d', estimatedCL)
    end
    
    disp(T)
    % findChainLength
    % parsScatterPlot
    % print zusammenfassung
    
    

end