import {defineStore} from 'pinia'
import {ref} from 'vue'
import{
    downloadHelthcertidetail,
    queryHerlthcertiList,
    modifyPrintConfirm,
    queryHelthcertiList,
    uploadMore,
    queryViewException
} from '@/apis/healthcertificatemanage/index.js'
export const usehealthcertificatemanageStore = defineStore('healthcertificatemanage',() => {
    //重写方法
    const getdownloadHelthcertidetail = async (params) => {
        return await downloadHelthcertidetail(params)
    }

    const getqueryHerlthcertiList = async (params) => {
        return await queryHerlthcertiList(params)
    }

    const getmodifyPrintConfirm = async (params) => {
        return await modifyPrintConfirm(params)
    }

    const putqueryHelthcertiList = async (params) => {
        return await queryHelthcertiList(params)
    }

    const postuploadMore = async (params) => {
        return await uploadMore(params)
    }

    const getqueryViewException = async (params) => {
        return await queryViewException(params)
    }
    //暴露出的数据
    return{
        getdownloadHelthcertidetail,
        getqueryHerlthcertiList,
        getmodifyPrintConfirm,
        putqueryHelthcertiList,
        postuploadMore,
        getqueryViewException
    }
})