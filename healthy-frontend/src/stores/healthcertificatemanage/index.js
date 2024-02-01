import {defineStore} from 'pinia'
import {ref} from 'vue'
import{
    downloadhelthcertidetail,
    queryherlthcertilist,
    modifyprintconfirm,
    queryHelthcertilist,
    uploadmore,
    queryviewexception
} from '@/apis/healthcertificatemanage/index.js'
export const usehealthcertificatemanageStore = defineStore('healthcertificatemanage',() => {
    //重写方法
    const getdownloadhelthcertidetail = async (params) => {
        return await downloadhelthcertidetail(params)
    }

    const getqueryherlthcertilist = async (params) => {
        return await queryherlthcertilist(params)
    }

    const getmodifyprintconfirm = async (params) => {
        return await modifyprintconfirm(params)
    }

    const putqueryHelthcertilist = async (params) => {
        return await queryHelthcertilist(params)
    }

    const postuploadmore = async (params) => {
        return await uploadmore(params)
    }

    const getqueryviewexception = async (params) => {
        return await queryviewexception(params)
    }
    //暴露出的数据
    return{
        getdownloadhelthcertidetail,
        getqueryherlthcertilist,
        getmodifyprintconfirm,
        putqueryHelthcertilist,
        postuploadmore,
        getqueryviewexception
    }
})