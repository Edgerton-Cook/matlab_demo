function [] = term(data)
    fprintf('Terminated Streaming!\n')
    if ~isempty(data.output_file_name)
        save(data.output_file_name,'data')
    end
end